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
 #include <QTcpSocket>
 #include <QSettings>

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

       //incializamos el socket :)

       socket = new QTcpSocket(this);
       //conectamos con el servidor
       socket->connectToHost(ipconfig->value("Configuracion_IP").toString(),2000);

       //Aqui creamos un fichero de configuraciion, en el que vamos a poner la ip
       ipconfig = new QSettings("./Configuracion_IP","IniFormat",this);


}


ImagineViewerWindow::~ImagineViewerWindow(){
    delete ui;
}


void ImagineViewerWindow :: recibir_imagen(const QImage& imagen,const QVector<QRect> &vector_rectangulos){
    QImage imagen2 = imagen;


    QPainter pintura(&imagen2 );

    pintura.drawRects(vector_rectangulos);


    QPixmap pixmap = QPixmap::fromImage ( imagen2 );
    // connvertir de imagen a pixmap con un metodo de Qpixmap
    //lo que hay que hacer en el cliente :)
    /* Ahora recibimos la imagen con el moviento, tenmos que el vector de rectngulos sea diferente de 0
      de esta forma mandamos solo las imagenes en las que halla movimiento, las recibimos en el servidor y se
      muestran alli, de manera que aqui ya no lo mostramos :)
    */

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

    //mostramos la imagen antes de mandarla.

    QPixmap pixmap = QPixmap::fromImage ( imagen );
    ui->Image->setPixmap(pixmap);

    emit enviar_imagen(imagen);

}


