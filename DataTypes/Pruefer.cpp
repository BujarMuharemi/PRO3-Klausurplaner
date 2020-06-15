//
// Created by cc on 15/6/20.
//

#include "Pruefer.h"

Pruefer::Pruefer(int pruefer1, int pruefer2) : pruefer1(pruefer1), pruefer2(pruefer2) {}

Pruefer::Pruefer(int pruefer1) : pruefer1(pruefer1) { this->pruefer2=NULL;}

int Pruefer::getPruefer1() const {
    return pruefer1;
}

int Pruefer::getPruefer2() const {
    return pruefer2;
}


