#ifndef IMAGINEVIEWERWINDOW_H
#define IMAGINEVIEWERWINDOW_H

#include <QMainWindow>

namespace Ui {
class ImagineViewerWindow;
}


class ImagineViewerWindow : public QMainWindow
{
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

#endif // IMAGINEVIEWERWINDOW_H
