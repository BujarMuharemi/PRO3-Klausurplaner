//
// Created by cc on 15/6/20.
//
#include <string>

#ifndef PRO3_KLAUSURPLANNER_STUDENT_H
#define PRO3_KLAUSURPLANNER_STUDENT_H


class Anmeldung {
    int mtkNR; //Matrikelnummer
    std::string stg; //Studiengang
    //int ID; //prufungsID
    int pNR;
    int pVersion;
public:
    Anmeldung(int mtkNr, const std::string &stg, int pNr, int pVersion);

private:

    bool isReady [20];

public:
    //Anmeldung(int mtkNr, std::string stg, int ID);



    int getMtkNr() const;

    const std::string &getStg() const;


    int getpVersion();


    int getPnr() const;

    int getPVersion() const;

    void resetReady();


};


#endif //PRO3_KLAUSURPLANNER_STUDENT_H
