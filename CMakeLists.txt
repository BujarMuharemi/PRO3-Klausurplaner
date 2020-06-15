cmake_minimum_required(VERSION 3.16)
project(PRO3_Klausurplanner)

set(CMAKE_CXX_STANDARD 14)

add_executable(PRO3_Klausurplanner
        InputData/Angebotene_Prüfungen_KL.csv
        InputData/Anmeldungen_WS2019_KL.csv
        InputData/Raumliste.csv
        main.cpp Readers/RaumlisteReader.h DataTypes/Raum.cpp DataTypes/Raum.h DataTypes/Student.cpp DataTypes/Student.h DataTypes/pTage.cpp DataTypes/pTage.h DataTypes/Klausur.cpp DataTypes/Klausur.h DataTypes/Pruefer.cpp DataTypes/Pruefer.h Readers/PruefungenReader.cpp Readers/PruefungenReader.h Readers/AnmeldungenReader.cpp Readers/AnmeldungenReader.h)
