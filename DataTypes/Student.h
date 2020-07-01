//
// Created by cc on 15/6/20.
//
#include <string>

#ifndef PRO3_KLAUSURPLANNER_STUDENT_H
#define PRO3_KLAUSURPLANNER_STUDENT_H


class Student {
    int mtkNR; //Matrikelnummer
    std::string stg; //Studiengang
    int ID;

    bool isReady [20];

public:
    Student(int mtkNr,  std::string stg, int ID);

    int getMtkNr() const;

    const std::string &getStg() const;

    int getID() const;

    void resetReady();


};


#endif //PRO3_KLAUSURPLANNER_STUDENT_H
