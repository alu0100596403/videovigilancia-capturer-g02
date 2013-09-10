#ifndef CLIENTE_H
#define CLIENTE_H

#include <Mensaje.pb.h>
#include <QThread>
#include <QTcpSocket>
#include <QMutex>
#include <QFile>
#include <QWaitCondition>
#include <QDebug>
#include <Mensaje.pb.h>
#include <QBuffer>
#include <QImage>
#include <QVector>
#include <QSettings>
#include <QDir>

class Cliente : public QThread
{
    Q_OBJECT
public:
    Cliente(int);
       ~Cliente();

signals:
    
public slots:

     void run(); // en este
     int get_cont();

private:

    int idsocket;
    static int cont;

    //Variable para poder bloquear el contador.

    static QMutex bloquear;

    QSettings *ipconfig; // fichero de configuracion

    QDir *direct; //Nombre del directorio que vamos a crear para las imagenes



};

#endif // CLIENTE_H
