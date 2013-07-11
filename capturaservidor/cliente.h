#ifndef CLIENTE_H
#define CLIENTE_H

#include <QThread>

class Cliente : public QThread
{
    Q_OBJECT
public:
    Cliente(int);
    void setIDs(int);
    int getIDs();

    
signals:
    
public slots:
    
private:

    int idsocket;
    static int cont;


};

#endif // CLIENTE_H
