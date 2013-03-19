#include "procesadora.h"

Procesadora::Procesadora(QObject *parent) :
    QObject(parent)
{
         // Desactivar la detección de sombras
            backgroundSubtractor.nmixtures = 3;

           // desactivar deteccion de movimiento
           backgroundSubtractor.bShadowDetection = false;
}


void Procesadora :: recibir_imagen(const QImage& imagen ) {

     qDebug() << Q_FUNC_INFO << QThread::currentThreadId();

     // AQUI VA EL CODIGO DE DECTECCION DE MOVIENTO

         // channels == 0 significa autodetección
         cv::Mat imagenmat=image2Mat(imagen);

         // std::vector<cv::Mat> images = <vector de imágenes en cv::Mat>

         // Definimos algunos tipos para que el código se lea mejor
         typedef std::vector<cv::Mat> ImagesType;
         typedef std::vector<std::vector<cv::Point> > ContoursType;

         // Instancia de la clase del sustractor de fondo
         // cv::BackgroundSubtractorMOG2(history=500,
         //                              varThreshold=16,
         //                              bShadowDetection=true)

             // Sustracción del fondo:
             //  1. El objeto sustractor compara la imagen en i con su
             //     estimación del fondo y devuelve en foregroundMask una
             //     máscara (imagen binaria) con un 1 en los píxeles de
             //     primer plano.
             //  2. El objeto sustractor actualiza su estimación del fondo
             //     usando la imagen en i.
             cv::Mat foregroundMask;
             backgroundSubtractor(imagenmat, foregroundMask);

             // Operaciones morfolóficas para eliminar las regiones de
             // pequeño tamaño. Erode() las encoge y dilate() las vuelve a
             // agrandar.
             cv::erode(foregroundMask, foregroundMask, cv::Mat());
             cv::dilate(foregroundMask, foregroundMask, cv::Mat());

             // Obtener los contornos que bordean las regiones externas
             // (CV_RETR_EXTERNAL) encontradas. Cada contorno es un vector
             // de puntos y se devuelve uno por región en la máscara.
             ContoursType contours;
             cv::findContours(foregroundMask, contours, CV_RETR_EXTERNAL,
                              CV_CHAIN_APPROX_NONE);

             // aqui tiene que ir un bucle que vaya por todos los vectores y se los pasamos aboundingRect
             // hay que pasar de CVrect a Qrect
             //Qvect vector
                cv::Rect rect;

             for (int i = 0; i < contours.length();i++){
                rect = cv::boundingRect(contours[i]);
                QRect rect1(rect.x, rect.y,rect.width, rect.height);
                QVector vector_rectangulo[i]=rect1;
             }



             // Aquí va el código ódigo que usa los contornos encontrados...
             // P. ej. usar  para obtener el cuadro
             // delimitador de cada uno y pintarlo en la imagen original
         }



     emit devolver_senal(imagen,vector_rectangulo); // se devuelve la imagen y el vector de rectangulos



 }



/*
// format == QImage::Format_Invalid significa autodetección
QImage mat2Image(const cv::Mat &mat,
                 QImage::Format format = QImage::Format_Invalid,
                 MatChannelOrder rgbOrder = MCO_BGR);

*/
