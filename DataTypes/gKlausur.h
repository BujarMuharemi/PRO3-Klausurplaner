//
// Created by cc on 1/7/20.
//
#include "Klausur.h"
#include "Raum.h"
#include <vector>


#ifndef PRO3_KLAUSURPLANNER_GKLAUSUR_H
#define PRO3_KLAUSURPLANNER_GKLAUSUR_H



class gKlausur {
    Klausur klausur;
    std::vector<Raum> raum;
    int teilnehmerZahl;
    int startZeit;

public:

    gKlausur(const Klausur &klausur, const std::vector<Raum> &raum, int teilnehmerZahl, int startZeit);

    const Klausur &getKlausur() const;

    void setKlausur(const Klausur &klausur);

    const std::vector<Raum> &getRaum() const;

    int getTeilnehmerZahl() const;

    void setTeilnehmerZahl(int teilnehmerZahl);

    int getStartZeit() const;

    void setStartZeit(int startZeit);


    std::string toCSV();






};


#endif //PRO3_KLAUSURPLANNER_GKLAUSUR_H
