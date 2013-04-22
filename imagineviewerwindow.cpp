#include "imagineviewerwindow.h"
#include "ui_imagineviewerwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QMovie>
#include <QLabel>
#include <QWaitCondition>
#include <QMutex>
#include <QDebug>
#include <QPainter>


 //// ESTE ES EL CODIGO DEL SERVIDOR

const int BufferSize = 20;       // Tamaño de la cola
QImage buffer[BufferSize];       // Cola de frames como array de C
int numUsedBufferItems = 0;      // Contador de frames en la cola

QWaitCondition bufferNotEmpty;
QWaitCondition bufferNotFull;
QMutex mutex;



ImagineViewerWindow::ImagineViewerWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::ImagineViewerWindow){

 movie_ = new QMovie();
    ui->setupUi(this);

    connect(movie_, SIGNAL(updated(const QRect&)),
            this, SLOT(on_movie_updated(const QRect&)));

//AQUI SERIA PONER LOS CONECTORES de los slots

       // Pasar la imagen a la instancia de SorterWorker
       connect(this, SIGNAL(enviar_imagen(const QImage&)),
           &procesadora, SLOT(recibir_imagen(const QImage& )));

       // Señal de que se ha recibido la imagen
       connect(&procesadora, SIGNAL(devolver_senal(const QImage&, const QVector <QRect>)),
           this, SLOT(recibir_imagen (const QImage&, const QVector <QRect>)));


       // Migrar la instancia de pocesadora al hilo de trabajo
       procesadora.moveToThread(&workingThread_);

       // Iniciar el hilo de trabajo
       workingThread_.start();

       // incializamoe el socket que nos conerctara con el cliente
       socket_server = new QTcpServer(this);

       //Tenemos que decirle al socket que escuche
       socket_server->listen(QHostAddress::Any, 2000);

       // al recibir una nueva peticion se crea el socket que conecta el servidor con el cliente
       connect(socket_server, SIGNAL(newConnection()), this, SLOT(crear_conexiones()));

       // esta seria la señal que conecta el cliente con el servidor
       connect(clientConnection, SIGNAL(readyRead()), this, SLOT(recibir_imagen()));

}


ImagineViewerWindow::~ImagineViewerWindow(){
    delete ui;
}


void ImagineViewerWindow :: recibir_imagen(){
   /*cuando ya recibimos la imagen tenemos que deserializar el mensaje, mostrar la imagen con el rectangulo,
    *que por cierto hay que fijarle su valor en el mensaje en el cliente para poder tenerlo aqui */


   /* QPixmap pixmap = QPixmap::fromImage ( imagen2 );
    // connvertir de imagen a pixmap con un metodo de Qpixmap

    ui->Image->setPixmap(pixmap);
    */

    const char *paquete =

    clientConnection->read();


    // Leer el mensaje
    std::string buffer;

    buffer.resize(sizeof(paquete));
    buffer = paquete;

    ifs.read(const_cast<char*>(buffer.c_str()), bufferSize);

    // Deserializar
    report.ParseFromString(buffer);
    // ahora tenemos que deserializar el mensaje recibido y mostrar




}

void ImagineViewerWindow :: crear_conexiones(){

    while(socket_server->hasPendingConnections()) {
      clientConnection = new socket_server->nextPendingConnection();


      emit clientConnection->readyRead();
    }

}

void ImagineViewerWindow::on_pushButton_clicked(){
    qApp->quit();

}


/*
void ImagineViewerWindow::on_actionAbrir_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(), tr("Img Files (*.mjpeg *.jpeg);;C++ Files (*.cpp *.h)"));

    if(!fileName.isEmpty()){
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)){
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        QImageReader imagereade(&file);
        QPixmap Pixmap = QPixmap::fromImageReader(&imagereade);
        ui->Image->setPixmap(Pixmap);
        file.close();
    }

}
*/



void ImagineViewerWindow::on_actionAbrir_triggered(){

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(), tr("Img Files (*.mjpeg *.jpeg);;C++ Files (*.cpp *.h)"));

    if(!fileName.isEmpty()){
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)){
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }

    movie_->setFileName(fileName);
        if (!movie_->isValid()) {
         QMessageBox::critical(this, tr("Error"),
            tr("No se pudo abrir el archivo o el formato"
               " es inválido"));
         return;
        }
    movie_->start();    // Iniciar la reproducción de la animación
    }

}




void ImagineViewerWindow::on_movie_updated(const QRect& ){

    QImage imagen = movie_->currentImage();
    emit enviar_imagen(imagen);

}


