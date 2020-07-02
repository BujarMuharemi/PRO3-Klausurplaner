//
// Created by cc on 1/7/20.
//

#include "TimeSlot.h"

TimeSlot::TimeSlot(const std::vector<gKlausur> &geplanteKlausurListe) : geplanteKlausurListe(geplanteKlausurListe) {}

TimeSlot::TimeSlot() {}

const std::vector<gKlausur> &TimeSlot::getGeplanteKlausurListe() const {
    return geplanteKlausurListe;
}

void TimeSlot::setGeplanteKlausurListe(std::vector<gKlausur> &geplanteKlausurListe) {
    TimeSlot::geplanteKlausurListe = geplanteKlausurListe;
}