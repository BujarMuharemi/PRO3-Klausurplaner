#ifndef PRO3_KLAUSURPLANNER_ANMELDUNGENREADER_H
#define PRO3_KLAUSURPLANNER_ANMELDUNGENREADER_H


#include <vector>
#include "../DataTypes/Student.h"

class AnmeldungenReader {
public:
    static void read(std::vector<Student>& studenten);

};


#endif //PRO3_KLAUSURPLANNER_ANMELDUNGENREADER_H
