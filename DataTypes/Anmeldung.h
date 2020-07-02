//
// Created by cc on 15/6/20.
//
#include <string>

#ifndef PRO3_KLAUSURPLANNER_STUDENT_H
#define PRO3_KLAUSURPLANNER_STUDENT_H


class Anmeldung {
    int mtkNR;
    std::string stg;
    int pNR;
    int pVersion;
public:
    Anmeldung(int mtkNr, const std::string &stg, int pNr, int pVersion);


    bool isReady [20] = {true};


    int getMtkNr() const;

    const std::string &getStg() const;


    int getPnr() const;

    int getPVersion() const;


    void resetReady();
    void setIsReady(int index, int dauer);
    bool getIsReady(int index, int dauer);


};


#endif //PRO3_KLAUSURPLANNER_STUDENT_H
