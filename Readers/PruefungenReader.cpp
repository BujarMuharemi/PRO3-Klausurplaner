#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include "PruefungenReader.h"

using namespace std;

void PruefungenReader::read(int pID[], string modul[], int pruefer1[], int pruefer2[], int dauer[]) {

    ifstream csvread;
    string temp[10000];
    string pversion[1000];
    string pnr[1000];
    string pruefer1S[1000];
    string pruefer2S[1000];
    string dauerS[1000];
    int counter1 = 0;
    int counter2 = 0;

    csvread.open("../InputData/Angebotene_Prüfungen_KL.csv", ios::in);

    if(csvread) {
        string s = "";
        while (getline(csvread, s, ';')) {
            temp[counter1] = s;
            counter1++;
        }
        csvread.close();
    }
    else{
        cerr << "Fehler beim Lesen!" << endl;
    }

    for(int i=16; i<10000; i=i+12){
        modul[counter2] = temp[i];
        counter2++;
    }
    counter2 = 0;

    for(int i=17; i<10000; i=i+12){
        pruefer1S[counter2] = temp[i];
        counter2++;
    }
    counter2 = 0;

    for(int i=19; i<10000; i=i+12){
        pruefer2S[counter2] = temp[i];
        counter2++;
    }
    counter2 = 0;

    for(int i=21; i<10000; i=i+12){
        dauerS[counter2] = temp[i];
        counter2++;
    }
    counter2 = 0;

    for(int i=14; i<10000; i=i+12){
        pversion[counter2] = temp[i];
        counter2++;
    }
    counter2 = 0;

    for(int i=15; i<10000; i=i+12){
        pnr[counter2] = temp[i];
        counter2++;
    }
    counter2 = 0;


    //strings in int arrays umwandeln wo nötig
    for(int i=0; i<1000; i++){
        pruefer1[i] = atoi(pruefer1S[i].c_str());
    }

    for(int i=0; i<1000; i++){
        pruefer2[i] = atoi(pruefer2S[i].c_str());
    }

    for(int i=0; i<1000; i++){
        dauer[i] = atoi(dauerS[i].c_str());
    }
    //hier entsteht ID
    for(int i=0; i<1000; i++){
        pID[i] = atoi(pnr[i].c_str()) - atoi(pversion[i].c_str());
    }


}
