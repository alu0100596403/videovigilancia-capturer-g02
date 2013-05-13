#ifndef IMAGINEVIEWERWINDOW_H
#define IMAGINEVIEWERWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include"procesadora.h"
#include <QThread>
#include <QTcpServer>
#include <QTcpSocket>
#include <QSettings>

namespace Ui {
class ImagineViewerWindow;
}

class ImagineViewerWindow : public QMainWindow {

    Q_OBJECT
    
    public:
        explicit ImagineViewerWindow(QWidget *parent = 0);
        ~ImagineViewerWindow();
    
    private slots:
        void on_pushButton_clicked();

        void on_actionAbrir_triggered();

        void on_movie_updated(const QRect& rect);

        void recibir_imagen();

        void crear_conexiones();

    private:
        Ui::ImagineViewerWindow *ui;

        QSettings *ipconfig;
        QMovie *movie_;
        QThread workingThread_;
        Procesadora procesadora;
        //socket del servidor
        QTcpServer *socket_server;

        // socket del cliente
        QTcpSocket *clientConnection;
        int sz; //para que entre en el bucle

    signals:
        // Señal para comunicarnos con el hilo de trabajo
        void enviar_imagen(const QImage& imagen);

};











#endif // IMAGINEVIEWERWINDOW_H


