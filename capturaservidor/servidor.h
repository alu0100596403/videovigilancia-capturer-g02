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

class Servidor : public QTcpServer
{
    Q_OBJECT
public:
    Servidor(QTcpServer *parent = 0);

    void incomingConnection(qintptr);



private slots:


private:

        QSettings *ipconfig; // fichero de configuracion



       QVector <Cliente*> ListaCliente; //Lista de clientes



    
};

#endif // SERVIDOR_H



