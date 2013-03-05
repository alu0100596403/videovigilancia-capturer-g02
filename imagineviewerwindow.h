#ifndef IMAGINEVIEWERWINDOW_H
#define IMAGINEVIEWERWINDOW_H

#include <QMainWindow>

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

private:
    Ui::ImagineViewerWindow *ui;
    QMovie *movie_;
};


class MyThread : public QThread
{
    Q_OBJECT

    protected:
        void run();
};


class Sorter : public QObject
{
    Q_OBJECT

    public:
        Sorter();
        ~Sorter();

        // Ordenar asíncronamente un vector en el hilo de trabajo
        void sortAsync(const QVector<int>& list);

    signals:
        // Señal para comunicarnos con el hilo de trabajo
        void sortingRequested(const QVector<int> &list);

    private slots:
        // Slot para saber cuando el vector ha sido ordenado
        void vectorSorted(const QVector<int> &list);

    private:
        // Clase del hilo de trabajo
        QThread workingThread_;
        // Clase que hace el ordenamiento
        SorterWorker sorterWorker_;
};


private slots:
    // Otros slots...
    //
    // void on_actionOpen_triggered();
    //
    // ...
    //
    void on_movie_updated(const QRect& rect);

	void MovieViewerWindow::on_movie_updated(const QRect& rect){
    QPixmap pixmap = movie_->currentPixmap();
    ui->label->setPixmap(pixmap);
}

#endif // IMAGINEVIEWERWINDOW_H


