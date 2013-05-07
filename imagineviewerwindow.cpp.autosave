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
#include <Mensaje.pb.h>
#include <QBuffer>

 //// ESTE ES EL CODIGO DEL SERVIDOR

const int BufferSize = 20;       // Tamaño de la cola
QImage buffer[BufferSize];       // Cola de frames como array de C
int numUsedBufferItems = 0;      // Contador de frames en la cola

QWaitCondition bufferNotEmpty;
QWaitCondition bufferNotFull;
QMutex mutex;



ImagineViewerWindow::ImagineViewerWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::ImagineViewerWindow){
    sz=0;

    qDebug() << "HOLA :) ";
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
           this, SLOT(recibir_imagen ()));


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


       qDebug() << "ADIOS :) ";


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

 QByteArray buffer;

 qDebug()<< "Viendo error bytes: " << clientConnection->bytesAvailable();

 while(true){
    if (sz == 0){
        if (clientConnection->bytesAvailable() >= sizeof(sz)){

            clientConnection->read((char*)&sz, sizeof(sz));

        }
        else break;

    }

    if ((sz != 0) && (clientConnection->bytesAvailable() >= sz)){
            buffer = clientConnection->read(sz);


            // Leer el mensaje
         std::string paquete(buffer.constData(), (size_t)buffer.size());

         Mensaje message;
          // Deserializar
        message.ParseFromString(paquete);
        QImage imagenM;


        std::string buffer;
        buffer = message.imagenes();

        // Leer el mensaje
        QBuffer buffer2;
        QByteArray aux(buffer.c_str() , buffer.length());


        buffer2.setBuffer(&aux);

        imagenM.load(&buffer2, "jpg");

        QPixmap pixmap = QPixmap::fromImage(imagenM);

        ui->Image->setPixmap(pixmap);

        // ahora tenemos que deserializar el mensaje recibido y mostrar
        sz=0;

        // deserializamos el mensaje


    }
    else break;
}

}

void ImagineViewerWindow :: crear_conexiones(){

    qDebug() << "Estoy creando una conexion";
    while(socket_server->hasPendingConnections()) {
      clientConnection = socket_server->nextPendingConnection();

      // esta seria la señal que conecta el cliente con el servidor
      connect(clientConnection, SIGNAL(readyRead()), this, SLOT(recibir_imagen()));

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


