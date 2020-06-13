cmake_minimum_required(VERSION 3.16)
project(PRO3_Klausurplanner)

set(CMAKE_CXX_STANDARD 14)

add_executable(PRO3_Klausurplanner
        InputData/Angebotene_Prüfungen_KL.csv
        InputData/Anmeldungen_WS2019_KL.csv
        InputData/Raumliste.csv
        main.cpp)
