//
// Created by cc on 15/6/20.
//
#include "Pruefer.h"


Pruefer::Pruefer(int pruefer){
    this->pruefer=pruefer;
}


int Pruefer::getPruefer() const {
    return this->pruefer;
}

void Pruefer::resetReady(){
    for(int i=0;i<20;i++){
        isReady[i]= true;
    }
}

void Pruefer::setIsReady(int index, int dauer) {

    for(int i = 0; i < dauer+1; i++){
        isReady[index+i] = false;
    }

}


