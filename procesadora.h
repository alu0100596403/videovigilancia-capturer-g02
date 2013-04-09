#ifndef PROCESADORA_H
#define PROCESADORA_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <opencv2/opencv.hpp>
#include <QVector>
#include <QRect>
#include <QTcpSocket>

class Procesadora : public QObject
{
    Q_OBJECT

private:

    cv::BackgroundSubtractorMOG2 backgroundSubtractor;

public:
    explicit Procesadora(QObject *parent = 0);

signals:
    // Señal emitida para devolver la imagen junto con el vector de rectangulos
      void devolver_senal(const QImage& imagen, const QVector <QRect> &vector_rectangulo);

public slots:

    // Método de la decteccion del moviento

   void recibir_imagen(const QImage& imagen );


    
};


#endif // PROCESADORA_H
