#include "servidor.h"



#include <QFile>
#include <QWaitCondition>
#include <QMutex>
#include <QDebug>
#include <Mensaje.pb.h>
#include <QBuffer>
#include <QImage>


Servidor::Servidor(QTcpServer *parent) : QTcpServer(parent) {

    sz=0;
    cont=0;

    ipconfig = new QSettings("/home/alex/Documentos/SOA/videovigilancia-capturer-g02/Configuracion_IP.ini",QSettings::IniFormat, this);
    direct = new QDir(ipconfig->value("ruta").toString());


    //AQUI SERIA PONER LOS CONECTORES de los slots

      // inicializamos el socket que nos conerctara con el cliente
      socket_server = new QTcpServer(this);

      //Tenemos que decirle al socket que escuche

     // socket_server->listen(QHostAddress::Any, 2000);

      socket_server->listen(QHostAddress::Any, ipconfig->value("puerto").toInt());

      // al recibir una nueva peticion se crea el socket que conecta el servidor con el cliente
      connect(socket_server, SIGNAL(newConnection()), this, SLOT(crear_conexiones()));
}


void Servidor :: incomingConnection(int IDs){

    QThread hilo;
    Cliente clien;
    clien.setIDs(IDs);
    hilo.start(clien);
    QTcpSocket sockclient;
    sockclient.setSocketDescriptor()


}



void Servidor :: crear_conexiones(){

    qDebug() << "Estoy creando una conexion";
    while(socket_server->hasPendingConnections()) {
      clientConnection = socket_server->nextPendingConnection();


      // esta seria la señal que conecta el cliente con el servidor
      connect(clientConnection, SIGNAL(readyRead()), this, SLOT(recibir_imagen()));

    }

}


void Servidor :: recibir_imagen(){
   /*cuando ya recibimos la imagen tenemos que deserializar el mensaje, mostrar la imagen con el rectangulo,
    *que por cierto hay que fijarle su valor en el mensaje en el cliente para poder tenerlo aqui */


   /* QPixmap pixmap = QPixmap::fromImage ( imagen2 );
    // connvertir de imagen a pixmap con un metodo de Qpixmap

    ui->Image->setPixmap(pixmap);
    */

 QByteArray buffer;

// qDebug()<< "Viendo error bytes: " << clientConnection->bytesAvailable();

 while(true){
    if (sz == 0){
        if (clientConnection->bytesAvailable() >= sizeof(sz)){
        //   qDebug()<< "Viendo error bytes2: " << clientConnection->bytesAvailable();

            clientConnection->read((char*)&sz, sizeof(sz));

        }
        else break;

    }

 //   qDebug()<< "Viendo error bytes3: " << clientConnection->bytesAvailable();

    if ((sz != 0) && (clientConnection->bytesAvailable() >= sz)){
         buffer = clientConnection->read(sz);
         qDebug()<< "Estoy recibiendo una imagen toda bonita " ;
             cont++; //Aumentamos el contador de xxxx.jpg porque hemos recibido una imagen

            // Leer el mensaje
         std::string paquete(buffer.constData(), (size_t)buffer.size());

         Mensaje message;
          // Deserializar
        message.ParseFromString(paquete);
        QImage imagenM;


        std::string buffer;
        buffer = message.imagenes();

        // Leer el mensaje
        QBuffer buffer2;
        QByteArray aux(buffer.c_str() , buffer.length());


        buffer2.setBuffer(&aux);

        imagenM.load(&buffer2, "jpg");

        QImage image2 = imagenM;

        QVector<QRect> rectangulo;



        for (int i=0; i < message.rectangulos_size(); i++){

            QRect Rectan(message.rectangulos(i).x(),message.rectangulos(i).y(),message.rectangulos(i).ancho(),message.rectangulos(i).alto());
            rectangulo.push_back(Rectan);
        }


        sz=0;


        QString hexa("%1");
        QString hexa2 = hexa.arg(cont, 50, 16, QLatin1Char('0'));

        //Creamos el nombre de las imagenes en hexadecimal


        QString carpetasup = hexa2.left(4);
        QString carpetainf = hexa2.mid(5,4);

        qDebug () << "Soy hexa: " << hexa2;

        //Creamos el nombre de la carpeta superior y las subcarpetas

        direct->mkdir(carpetasup);
        qDebug () << "soy carpeta sup" << carpetasup ;
        direct->mkdir(carpetasup+"/"+carpetainf); //Concatenamos la ruta vieja, con nuestra carpeta inferior.

        image2.save(direct->path()+"/"+carpetasup+"/"+carpetainf+"/"+hexa2+".jpg", "jpg", -1);


    }
    else break;
}



}
