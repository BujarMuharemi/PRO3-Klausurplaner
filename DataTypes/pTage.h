//
// Created by cc on 15/6/20.
//

#include "TimeSlot.h"
#include <vector>

#ifndef PRO3_KLAUSURPLANNER_PTAGE_H
#define PRO3_KLAUSURPLANNER_PTAGE_H


class pTage {
    TimeSlot timeSlots[20];
public:
    const TimeSlot *getTimeSlots() const;


    pTage();
};


#endif //PRO3_KLAUSURPLANNER_PTAGE_H
