//
// Created by cc on 15/6/20.
//
#include <string>

#ifndef PRO3_KLAUSURPLANNER_PRUEFER_H
#define PRO3_KLAUSURPLANNER_PRUEFER_H


class Pruefer {
    int pruefer1;
    int pruefer2;

public:
    Pruefer(int pruefer1, int pruefer2);

    Pruefer(int pruefer1);

    int getPruefer1() const;

    int getPruefer2() const;
};


#endif //PRO3_KLAUSURPLANNER_PRUEFER_H
