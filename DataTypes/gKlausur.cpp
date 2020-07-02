//
// Created by cc on 1/7/20.
//

#include "gKlausur.h"



const Klausur &gKlausur::getKlausur() const {
    return klausur;
}


void gKlausur::setKlausur(const Klausur &klausur) {
    gKlausur::klausur = klausur;
}

int gKlausur::getTeilnehmerZahl() const {
    return teilnehmerZahl;
}

void gKlausur::setTeilnehmerZahl(int teilnehmerZahl) {
    gKlausur::teilnehmerZahl = teilnehmerZahl;
}

int gKlausur::getStartZeit() const {
    return startZeit;
}

void gKlausur::setStartZeit(int startZeit) {
    gKlausur::startZeit = startZeit;
}

gKlausur::gKlausur(const Klausur &klausur, const std::vector<Raum> &raum, int teilnehmerZahl, int startZeit) : klausur(
        klausur), raum(raum), teilnehmerZahl(teilnehmerZahl), startZeit(startZeit) {}

const std::vector<Raum> &gKlausur::getRaum() const {
    return raum;
}



