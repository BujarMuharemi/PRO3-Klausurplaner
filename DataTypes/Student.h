//
// Created by cc on 15/6/20.
//
#include <string>

#ifndef PRO3_KLAUSURPLANNER_STUDENT_H
#define PRO3_KLAUSURPLANNER_STUDENT_H


class Student {
    int mtkNR; //Matrikelnummer
    std::string stg; //Studiengang

    //TODO: add ID, remove rest
    int pVersion; //Pruefungs Version
    int pNR;    //Pruefungs Nummer

    std::string pForm; //Pruefungsform
    std::string pFormTXT; // Pruefungsform ausgeschrieben
    int pSemester; // Pruefungssemster

    bool isReady [20];

public:
    Student(int mtkNr,  std::string stg, int pVersion, int pNr,  std::string pForm,
             std::string pFormTxt, int pSemester);

    int getMtkNr() const;

    const std::string &getStg() const;

    int getPVersion() const;

    int getPnr() const;

    const std::string &getPForm() const;

    const std::string &getPFormTxt() const;

    int getPSemester() const;

    void resetReady();


};


#endif //PRO3_KLAUSURPLANNER_STUDENT_H
