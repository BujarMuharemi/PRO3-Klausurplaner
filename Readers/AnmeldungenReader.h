#ifndef PRO3_KLAUSURPLANNER_ANMELDUNGENREADER_H
#define PRO3_KLAUSURPLANNER_ANMELDUNGENREADER_H


#include <vector>
#include "../DataTypes/Anmeldung.h"

class AnmeldungenReader {
public:
    static void read(std::vector<Anmeldung>& studenten);

};


#endif //PRO3_KLAUSURPLANNER_ANMELDUNGENREADER_H
