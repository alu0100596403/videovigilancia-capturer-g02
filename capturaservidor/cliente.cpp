#include "cliente.h"

int Cliente ::cont;
QMutex Cliente :: bloquear;

Cliente :: Cliente(int IDs) : QThread(){

    idsocket = IDs;



    ipconfig = new QSettings("/home/adri/Documentos/Tercer_Ano/SOA/1/videovigilancia-capturer-g02/capturaservidor/Configuracion_IP.ini",QSettings::IniFormat, this);
    direct = new QDir(ipconfig->value("ruta").toString());

    cont = ipconfig->value("cont").toInt();
}

int Cliente :: get_cont(){
    return cont;
}


/*
int Cliente::getIDs(){

    return idsocket;

}

void Cliente::setIDs(int IDs){

    idsocket = IDs; idn

}*/

void Cliente::run(){
     /*Creamos el socket del cliente, que se va a ejecutar el el hilo */

      QTcpSocket socket;

     socket.setSocketDescriptor(idsocket);

     int sz; // Variable para


while (true){

    socket.waitForReadyRead();

     /*cuando ya recibimos la imagen tenemos que deserializar el mensaje, mostrar la imagen con el rectangulo,
      *que por cierto hay que fijarle su valor en el mensaje en el cliente para poder tenerlo aqui */


   QByteArray buffer;

  // qDebug()<< "Viendo error bytes: " << clientConnection->bytesAvailable();

   while(true){
      if (sz == 0){
          if (socket.bytesAvailable() >= sizeof(sz)){
          //   qDebug()<< "Viendo error bytes2: " << clientConnection->bytesAvailable();

              socket.read((char*)&sz, sizeof(sz));

          }
          else break;

      }

   //   qDebug()<< "Viendo error bytes3: " << clientConnection->bytesAvailable();

      if ((sz != 0) && (socket.bytesAvailable() >= sz)){
           buffer = socket.read(sz);

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

          bloquear.lock();
          cont++; //Aumentamos el contador de xxxx.jpg porque hemos recibido una imagen

          QString hexa("%1");
          QString hexa2 = hexa.arg(cont, 50, 16, QLatin1Char('0'));

          bloquear.unlock();


          //Creamos el nombre de las imagenes en hexadecimal


          QString carpetasup = hexa2.left(4);
          QString carpetainf = hexa2.mid(5,4);

  //        qDebug () << "Soy hexa: " << hexa2;

          //Creamos el nombre de la carpeta superior y las subcarpetas

          direct->mkdir(carpetasup);
          direct->mkdir(carpetasup+"/"+carpetainf); //Concatenamos la ruta vieja, con nuestra carpeta inferior.

          image2.save(direct->path()+"/"+carpetasup+"/"+carpetainf+"/"+hexa2+".jpg", "jpg", -1);


      }
      else break;
  }


}

}

Cliente::~Cliente(){

        ipconfig->setValue("cont", cont);
    }

