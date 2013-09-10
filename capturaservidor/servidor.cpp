#include "servidor.h"
#include <QFile>
#include <QWaitCondition>
#include <QMutex>
#include <QDebug>
#include <Mensaje.pb.h>
#include <QBuffer>
#include <QImage>
#include <QVector>
#include <syslog.h>
#include <signal.h>
#include <QCoreApplication>
int Servidor :: sigHupSd[2];
int Servidor :: sigTermSd[2];


int setupUnixSignalHandlers(){
    struct :: sigaction hup, term;

    hup.sa_handler = &Servidor::hupSignalHandler;
    ::sigemptyset(&hup.sa_mask);
    hup.sa_flags = SA_RESTART;

    // Establecer manejador de la señal SIGHUP
    if (::sigaction(SIGHUP, &hup, 0) > 0)
    return 1;

    term.sa_handler = &Servidor::termSignalHandler;
    ::sigemptyset(&term.sa_mask);
    term.sa_flags = SA_RESTART;

    // Establecer manejador de la señal SIGTERM
    if (::sigaction(SIGTERM, &term, 0) > 0)
    return 2;

    return 0;
}



Servidor::Servidor(QTcpServer *parent) : QTcpServer(parent) {

    ipconfig = new QSettings("/home/adri/Documentos/Tercer_Ano/SOA/1/videovigilancia-capturer-g02/capturaservidor/Configuracion_IP.ini",QSettings::IniFormat, this);

    // Crear las parejas de sockets UNIX
        if (::socketpair(AF_UNIX, SOCK_STREAM, 0, sigHupSd))
            qFatal("Couldn't create HUP socketpair");
        if (::socketpair(AF_UNIX, SOCK_STREAM, 0, sigTermSd))
            qFatal("Couldn't create TERM socketpair");

        // Crear los objetos para monitorizar uno de los socket
        // de cada pareja.
        sigHupNotifier = new QSocketNotifier(sigHupSd[1],QSocketNotifier::Read, this);
        sigTermNotifier = new QSocketNotifier(sigTermSd[1],QSocketNotifier::Read, this);

        // Conectar la señallisten(QHostAddress::Any, 2000); activated() de cada objeto
        // QSocketNotifier con el slot correspondiente. Esta señal
        // será emitida cuando hayan datos para ser leidos en el
        // socket monitorizado.
        connect(sigHupNotifier, SIGNAL(activated(int)), this,
            SLOT(handleSigHup()));
        connect(sigTermNotifier, SIGNAL(activated(int)), this,
            SLOT(handleSigTerm()));
        setupUnixSignalHandlers();


        // escuchamos
        listen(QHostAddress::Any, ipconfig->value("puerto").toInt());

}

//
// Manejador de la señal SIGHUP
//
void Servidor::hupSignalHandler(int){
    char a = 1;
    ::write(sigHupSd[0], &a, sizeof(a));
}

//
// Manejador de la señal SIGTERM
//
void Servidor::termSignalHandler(int){

    char a = 1;
    ::write(sigTermSd[0], &a, sizeof(a));
}

//
// Configurar los manejadores de señal
//

void Servidor::handleSigHup()
{
    sigHupNotifier->setEnabled(false);
    char tmp;
    ::read(sigHupSd[1], &tmp, sizeof(tmp));

    //CODIGO PARA RECARGAR
    //eliminar el objeto y crear uno nuevo



    qApp->exit(10);



    sigHupNotifier->setEnabled(true);
}

void Servidor::handleSigTerm()
{
    sigTermNotifier->setEnabled(false);
    char tmp;
    ::read(sigTermSd[1], &tmp, sizeof(tmp));

    //codigo para terminar

    // se almacena el valor del contador.

        syslog(LOG_NOTICE, "Detectado el sigTerm\n");
    qApp->quit();




    sigTermNotifier->setEnabled(true);
}



void Servidor :: incomingConnection(qintptr IDs){

    syslog(LOG_NOTICE, "estoy creando un cliente \n");


    Cliente *clien = new Cliente(IDs);
    ListaCliente.push_back(clien);
    clien->start();

    syslog(LOG_NOTICE, "creado \n");

}
Servidor :: ~Servidor(){



}
