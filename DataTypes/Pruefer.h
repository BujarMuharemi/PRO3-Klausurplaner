//
// Created by cc on 15/6/20.
//
#include <string>

#ifndef PRO3_KLAUSURPLANNER_PRUEFER_H
#define PRO3_KLAUSURPLANNER_PRUEFER_H


class Pruefer {
    int pruefer;
    bool isReady [20] = {true};

public:
    Pruefer(int pruefer);

    int getPruefer() const;

    void resetReady();
    void setIsReady(int index, int dauer);
    bool getIsReady(int index, int dauer);

};


#endif //PRO3_KLAUSURPLANNER_PRUEFER_H
