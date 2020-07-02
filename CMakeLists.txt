cmake_minimum_required(VERSION 3.16)
project(PRO3_Klausurplanner)

set(CMAKE_CXX_STANDARD 14)

include_directories(DataTypes)
include_directories(Readers)

add_executable(PRO3_Klausurplanner
    DataTypes/Anmeldung.cpp
    DataTypes/Anmeldung.h
    DataTypes/gKlausur.cpp
    DataTypes/gKlausur.h
    DataTypes/Klausur.cpp
    DataTypes/Klausur.h
    DataTypes/Pruefer.cpp
    DataTypes/Pruefer.h
    DataTypes/pTage.cpp
    DataTypes/pTage.h
    DataTypes/Raum.cpp
    DataTypes/Raum.h
    DataTypes/TimeSlot.cpp
    DataTypes/TimeSlot.h
    InputData/Angebotene_Prüfungen_KL.csv
    InputData/Anmeldungen_WS2019_KL.csv
    InputData/Raumliste.csv
    Readers/AnmeldungenReader.cpp
    Readers/AnmeldungenReader.h
    Readers/PruefungenReader.cpp
    Readers/PruefungenReader.h
    Readers/RaumlisteReader.cpp
    Readers/RaumlisteReader.h
    main.cpp)
