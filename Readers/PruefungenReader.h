#ifndef PRO3_KLAUSURPLANNER_PRUEFUNGENREADER_H
#define PRO3_KLAUSURPLANNER_PRUEFUNGENREADER_H

#include "../DataTypes/Klausur.h"
#include <vector>


class PruefungenReader {
public:
    static void read(std::vector<Klausur>& klausuren, std::vector<Pruefer>& pruefer);
};


#endif //PRO3_KLAUSURPLANNER_PRUEFUNGENREADER_H
