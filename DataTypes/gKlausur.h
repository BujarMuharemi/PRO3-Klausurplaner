//
// Created by cc on 1/7/20.
//
#include "Klausur.h"
#include "Raum.h"


#ifndef PRO3_KLAUSURPLANNER_GKLAUSUR_H
#define PRO3_KLAUSURPLANNER_GKLAUSUR_H


class gKlausur {
    Klausur klausur;
    Raum raum;
    int teilnehmerZahl;
    int startZeit;

public:
    const Klausur &getKlausur() const;

    void setKlausur(const Klausur &klausur);

    const Raum &getRaum() const;

    void setRaum(const Raum &raum);

public:
    gKlausur(const Klausur &klausur, const Raum &raum,const int &teilnehmerZahl,const int &startZeit);
};


#endif //PRO3_KLAUSURPLANNER_GKLAUSUR_H
