//
// Created by cc on 15/6/20.
//

#include <string>

#ifndef PRO3_KLAUSURPLANNER_RAUM_H
#define PRO3_KLAUSURPLANNER_RAUM_H


class Raum {
    std::string Name;
    int Sitzplaetze;

    bool isReady [20] = {true};

public:
    Raum();
    Raum(std::string Name,int Sitzplaetze);
    std::string getName();
    int getSitzplaetze();

    bool getIsReady(int index, int dauer);
    void setIsReady(int index, int dauer);
    void resetReady();
};


#endif //PRO3_KLAUSURPLANNER_RAUM_H
