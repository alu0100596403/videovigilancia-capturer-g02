#include "imagineviewerwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImagineViewerWindow w;
    w.show();
    
    return a.exec();
}
