#include "cliente.h"

Cliente::Cliente(int IDs) : QThread(parent){

    idsocket = IDs;

}


int Cliente::getIDs(){

    return idsocket;

}

void Cliente::setIDs(int IDs){

    idsocket = IDs;

}
