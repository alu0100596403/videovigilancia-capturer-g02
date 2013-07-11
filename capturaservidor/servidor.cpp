#include "servidor.h"



#include <QFile>
#include <QWaitCondition>
#include <QMutex>
#include <QDebug>
#include <Mensaje.pb.h>
#include <QBuffer>
#include <QImage>
#include <QVector>


Servidor::Servidor(QTcpServer *parent) : QTcpServer(parent) {

    ipconfig = new QSettings("/home/adri/Documentos/Tercer_Ano/SOA/1/videovigilancia-capturer-g02/capturaservidor/Configuracion_IP.ini",QSettings::IniFormat, this);

    //Tenemos que decirle al socket que escuche
    qDebug()<< "estoy en el constructor  " ;

}


void Servidor :: incomingConnection(qintptr IDs){
    qDebug()<< "estoy creando un cliente  " ;


    Cliente *clien = new Cliente(IDs);
    ListaCliente.push_back(clien);
    clien->start();
    qDebug()<< "ya lo cree " ;

}


