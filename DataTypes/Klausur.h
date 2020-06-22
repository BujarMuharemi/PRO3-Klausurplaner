//
// Created by cc on 15/6/20.
//
#include <string>
#include "Pruefer.h"

#ifndef PRO3_KLAUSURPLANNER_KLAUSUR_H
#define PRO3_KLAUSURPLANNER_KLAUSUR_H


class Klausur {
    std::string stg; //Studiengang
    int pVersion; //Pruefungs Version
    int pNR;    //Pruefungs Nummer
    int ID; // -> selbst generiert ?
    std::string pName;
    Pruefer pruefer;
    int pDauer;
    std::string pForm; //Pruefungsform DELETE
    int pSemester; // Pruefungssemster DELETE

public:
    Klausur(const std::string &stg, int pVersion, int pNr, const std::string &pName, const Pruefer &pruefer, int pDauer,
            const std::string &pForm, int pSemester);
    int getID();
};


#endif //PRO3_KLAUSURPLANNER_KLAUSUR_H
