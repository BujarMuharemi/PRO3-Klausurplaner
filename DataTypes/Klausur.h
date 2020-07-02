//
// Created by cc on 15/6/20.
//
#include <string>
#include "Pruefer.h"

#ifndef PRO3_KLAUSURPLANNER_KLAUSUR_H
#define PRO3_KLAUSURPLANNER_KLAUSUR_H



class Klausur {
    int pVersion;
    int pNR;
    int ID;
    std::string pName;
    int pruefer1;
    int pruefer2;
    int pDauer;

public:
    Klausur(int pVersion, int pNr, int id, const std::string &pName, int pruefer1, int pruefer2, int pDauer);

    int getID();
    int getpVersion();
    int getpNR();
    std::string getpName();
    int getpruefer1();
    int getpruefer2();
    int getpDauer();

    int getDauerTimeSlot();

    void setPDauer(int pDauer);

};


#endif //PRO3_KLAUSURPLANNER_KLAUSUR_H
