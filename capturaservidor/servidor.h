#ifndef SERVIDOR_H
#define SERVIDOR_H

#include "cliente.h"

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QTcpServer>
#include <QTcpSocket>
#include <QSettings>
#include <QDir>
#include<QVector>
#include<QSocketNotifier>
#include <sys/socket.h>
#include <sys/types.h>

class Servidor : public QTcpServer
{
    Q_OBJECT
public:
    Servidor(QTcpServer *parent = 0);

    void incomingConnection(qintptr);

    // Manejadores de señal POSIX
    static void hupSignalHandler(int unused);
    static void termSignalHandler(int unused);

    ~Servidor();

public slots:

    // Slots Qt donde atender las señales POSIX
    void handleSigHup();
    void handleSigTerm();


private:

       QSettings *ipconfig; // fichero de configuracion
       QVector <Cliente*> ListaCliente; //Lista de clientes

       // Pares de sockets. Un par por señal a manejar
       static int sigHupSd[2];
       static int sigTermSd[2];

       // Objetos para monitorizar los pares de sockets
       QSocketNotifier *sigHupNotifier;
       QSocketNotifier *sigTermNotifier;



    
};

#endif // SERVIDOR_H



