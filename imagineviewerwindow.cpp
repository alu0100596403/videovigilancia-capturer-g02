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



ImagineViewerWindow::ImagineViewerWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::ImagineViewerWindow)
{

    ui->setupUi(this);
   movie_ = new QMovie("video.mjpeg");
    ui->Image->setMovie(movie_);
}



ImagineViewerWindow::~ImagineViewerWindow()
{
    delete ui;
}


void ImagineViewerWindow::on_pushButton_clicked()
{
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

void ImagineViewerWindow::on_actionAbrir_triggered()
{
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
