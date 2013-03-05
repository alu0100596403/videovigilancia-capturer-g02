#include "imagineviewerwindow.h"
#include "ui_imagineviewerwindow.h"
#include <Qfile>
#include <QFileDialog>
#include <QMessageBox>
#include <QMovie>
#include <Qlabel>


/*
ImagineViewerWindow::ImagineViewerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ImagineViewerWindow)
{
    ui->setupUi(this);
}
*/

ImagineViewerWindow::ImagineViewerWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::ImagineViewerWindow){

 movie_ = new QMovie();
    // ui->label->setMovie(movie_);
    connect(movie_, SIGNAL(updated(const QRect&)),
            this, SLOT(on_movie_updated(const QRect&)));

}

ImagineViewerWindow::~ImagineViewerWindow(){
    delete ui;
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

void MyThread::run(){

    // Aquí el código a ejecutar en el hilo...
}

void MovieViewerWindow::on_movie_updated(const QRect& rect){
    QPixmap pixmap = movie_->currentPixmap();
    ui->label->setPixmap(pixmap);
}



Sorter::Sorter() : QObject(){
    qDebug() << Q_FUNC_INFO << QThread::currentThreadId();

    // Registrar los parámetros de la señales. Necesitamos registrar
    // QList<int> porque no es un tipo conocido por el sistema de
    // meta-objetos de Qt.
    qRegisterMetaType< QVector<int> >("QVector<int>");

    // Pasar la petición de ordenar a la instancia de SorterWorker
    connect(this, SIGNAL(sortingRequested(QVector<int>)),
        &sorterWorker_, SLOT(doSort(QVector<int>)));
    // Ser notificado cuando el vector haya sido ordenado
    connect(&sorterWorker_, SIGNAL(vectorSorted(QVector<int>)),
        this, SLOT(vectorSorted(QVector<int>)));

    // Migrar la instancia de SorterWorker al hilo de trabajo
    sorterWorker_.moveToThread(&workingThread_);

    // Iniciar el hilo de trabajo
    workingThread_.start();
}

Sorter::~Sorter(){

    // Le decimos al bucle de mensajes del hilo que se detenga
    workingThread_.quit();
    // Ahora esperamos a que el hilo de trabajo termine
    workingThread_.wait();
}

void Sorter::sortAsync(const QVector<int>& list){
    qDebug() << Q_FUNC_INFO << QThread::currentThreadId();

    emit sortingRequested(list);
}

void Sorter::vectorSorted(const QVector<int>& list){
    qDebug() << list;
}