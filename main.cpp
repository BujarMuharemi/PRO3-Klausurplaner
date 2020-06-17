#include <iostream>
#include <fstream>
#include <string>
#include "DataTypes/Raum.h"
#include "DataTypes/Student.h"
#include "DataTypes/Pruefer.h"
#include "DataTypes/Klausur.h"
#include "Readers/RaumlisteReader.h"
#include "Readers/PruefungenReader.h"


using namespace std;

int main(){

    Student b(123456,"IF",234234,234234,"KL","Klausur",20192);
    Raum a("asdf",4);
    Pruefer pPaar(6317,452);
    Pruefer p1(666);
//-------------------------------------------------------------------RaumlisteReader
    string nummer [1000];
    int plaetze [1000];

    RaumlisteReader::read(nummer, plaetze);
//--------------------------------------------------------------------PrüfungenReader
    int pID[1000];
    string modul[1000];
    int pruefer1[1000];
    int pruefer2[1000];
    int dauer[1000];

    PruefungenReader::read(pID, modul, pruefer1, pruefer2, dauer);
    
    for(int i = 0; i < 544; i++){
        cout<< "pID: " << pID[i]  << "; modul: " << modul[i] << "; pruefer1: " << pruefer1[i] << "; pruefer2: " << pruefer2[i] << "; dauer: " << dauer[i] << endl;
    }
//--------------------------------------------------------------------
    Klausur k("AB",141,1030,"Technik Grundlagen",pPaar,210,"KL",20201);

    /*cout << "Prüfer parr: 1:" << pPaar.getPruefer1()<< " 2:"<<pPaar.getPruefer2()<<endl;

    cout << "Hello World" << a.getSitzplaetze() << endl;

    cout << "ID: " << k.getID() << endl;

    for(int i = 0; i < 54; i++){
        cout << "Raum: " << nummer[i] << "; Sitzplätze: " << plaetze[i] << endl;
    }*/

    return 0;
}