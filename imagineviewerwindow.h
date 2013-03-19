#ifndef IMAGINEVIEWERWINDOW_H
#define IMAGINEVIEWERWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include"procesadora.h"
#include <Qthread>

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

        void recibir_imagen(const QImage& imagen, const QVector vector_rectangulos); // este ademas recibe el vector de rectagulos y muestra la imagen y los rectangulos

    private:
        Ui::ImagineViewerWindow *ui;

        QMovie *movie_;
        QThread workingThread_;
        Procesadora procesadora;

    signals:
        // Señal para comunicarnos con el hilo de trabajo
        void enviar_imagen(const QImage& imagen);
};











#endif // IMAGINEVIEWERWINDOW_H


