#include <iostream>
#include <fstream>
#include <string>
#include "DataTypes/Raum.h"
#include "DataTypes/Student.h"
#include "DataTypes/Pruefer.h"
#include "DataTypes/Klausur.h"
#include "Readers/RaumlisteReader.h"


using namespace std;

int main(){

    Student b(123456,"IF",234234,234234,"KL","Klausur",20192);
    Raum a("asdf",4);
    Pruefer pPaar(6317,452);
    Pruefer p1(666);

    string nummer [1000];
    int plaetze [1000];

    RaumlisteReader::read(nummer, plaetze);

    Klausur k("AB",141,1030,"Technik Grundlagen",pPaar,210,"KL",20201);

    cout << "Prüfer parr: 1:" << pPaar.getPruefer1()<< " 2:"<<pPaar.getPruefer2()<<endl;

    cout << "Hello World" << a.getSitzplaetze() << endl;

    cout << "ID: " << k.getID() << endl;

    for(int i = 0; i < 54; i++){
        cout << "Raum: " << nummer[i] << "; Sitzplätze: " << plaetze[i] << endl;
    }

    return 0;
}