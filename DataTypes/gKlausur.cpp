//
// Created by cc on 1/7/20.
//

#include "gKlausur.h"

gKlausur::gKlausur(const Klausur &klausur, const Raum &raum,const int &teilnehmerZahl,const int &startZeit) : klausur(klausur), raum(raum) {}

const Klausur &gKlausur::getKlausur() const {
    return klausur;
}

void gKlausur::setKlausur(const Klausur &klausur) {
    gKlausur::klausur = klausur;
}

const Raum &gKlausur::getRaum() const {
    return raum;
}

void gKlausur::setRaum(const Raum &raum) {
    gKlausur::raum = raum;
}
