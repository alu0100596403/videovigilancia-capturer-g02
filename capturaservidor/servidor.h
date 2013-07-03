#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QTcpServer>
#include <QTcpSocket>
#include <QSettings>
#include <QDir>

class Servidor : public QObject
{
    Q_OBJECT
public:
    explicit Servidor(QObject *parent = 0);


private slots:

        void recibir_imagen();

        void crear_conexiones();


private:

        QSettings *ipconfig;

        //socket del servidor
        QTcpServer *socket_server;

        // socket del cliente
        QTcpSocket *clientConnection;
        int sz; //para que entre en el bucle

        int cont; //Contador para el nombre del fichero

        QDir *direct; //Nombre del directorio que vamos a crear para las imagenes



    signals:
        // Señal para comunicarnos con el hilo de trabajo
        void enviar_imagen(const QImage& imagen);

    
};

#endif // SERVIDOR_H
