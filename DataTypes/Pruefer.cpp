//
// Created by cc on 15/6/20.
//
#include "Pruefer.h"


Pruefer::Pruefer(int pruefer) : pruefer(pruefer) {}

int Pruefer::getPruefer() const {
    return pruefer;
}

void Pruefer::resetReady(){
    for(int i=0;i<20;i++){
        isReady[i]= true;
    }
}


