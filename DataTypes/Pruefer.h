//
// Created by cc on 15/6/20.
//
#include <string>

#ifndef PRO3_KLAUSURPLANNER_PRUEFER_H
#define PRO3_KLAUSURPLANNER_PRUEFER_H


class Pruefer {
    int pruefer;
    bool isReady [20]; // TODO: check default ?

public:
    Pruefer(int pruefer);

    int getPruefer() const;

    void resetReady();
};


#endif //PRO3_KLAUSURPLANNER_PRUEFER_H
