//
// Created by cc on 15/6/20.
//

#include <string>

#ifndef PRO3_KLAUSURPLANNER_RAUM_H
#define PRO3_KLAUSURPLANNER_RAUM_H


class Raum {
    std::string Name;
    int Sitzplaetze;

public:
    Raum(std::string Name,int Sitzplaetze);
    std::string getName();
    int getSitzplaetze();
};


#endif //PRO3_KLAUSURPLANNER_RAUM_H
