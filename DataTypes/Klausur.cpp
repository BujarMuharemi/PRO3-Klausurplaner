//
// Created by cc on 15/6/20.
//

#include "Klausur.h"

Klausur::Klausur(const std::string &stg, int pVersion, int pNr, const std::string &pName, const Pruefer &pruefer,
                 int pDauer, const std::string &pForm, int pSemester) : stg(stg), pVersion(pVersion), pNR(pNr),
                                                                        pName(pName), pruefer(pruefer), pDauer(pDauer),
                                                                        pForm(pForm), pSemester(pSemester) {
    this->ID=pNr+pVersion;
}

int Klausur::getID() {
    return this->ID;
}

