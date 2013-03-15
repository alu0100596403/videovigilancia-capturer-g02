#ifndef PROCESADORA_H
#define PROCESADORA_H

#include <QObject>
#include <QDebug>
#include<QThread>
class Procesadora : public QObject
{
    Q_OBJECT
public:
    explicit Procesadora(QObject *parent = 0);

signals:
    // Señal emitida cuando el vector ha sido ordenado
      void devolver_senal(const QImage& imagen);

public slots:
    // Método encargado del ordenamiento

   void recibir_imagen(const QImage& imagen );


    
};


#endif // PROCESADORA_H
