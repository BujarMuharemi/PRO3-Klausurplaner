#include <iostream>
#include <fstream>
#include <string>
#include "DataTypes/Raum.h"
#include "DataTypes/Student.h"
#include "DataTypes/Pruefer.h"
#include "DataTypes/Klausur.h"
#include "Readers/RaumlisteReader.h"
#include "Readers/PruefungenReader.h"
#include "Readers/AnmeldungenReader.h"
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    cout << "<Raumliste------------------------------------------------------------------>" << endl;
    vector<Raum> raume;
    RaumlisteReader::read(raume);

    for(auto & i : raume){
        cout << "Raum: "  << i.getName() << "; Plätze: " << i.getSitzplaetze() << endl;
    }


    cout << "<Prüfungen------------------------------------------------------------------>" << endl;
    vector<Klausur> klausuren;
    vector<Pruefer> pruefer;
    PruefungenReader::read(klausuren, pruefer);

    for(auto & i : klausuren){
        cout << "PNR: " << i.getpNR() << "; PVersion: "  << i.getpVersion()  << "; ID: " << i.getID()  << "; pName: "  << i.getpName() << "; Prüfer1: "  << i.getpruefer1() << "; Prüfer2: "  << i.getpruefer2()  << "; Dauer: " << i.getpDauer() <<endl;
    }

    for(auto & i : pruefer){
        cout << "Pruefer_ID: " << i.getPruefer() << endl;
    }


    cout << "<Anmeldungen------------------------------------------------------------------>" << endl;
    vector<Student> studenten;
    AnmeldungenReader::read(studenten);


    for(auto & i : studenten){
        cout << "MtkNR: " << i.getMtkNr() << "; Studiengang: " << i.getStg() << "; ID: " << i.getID() << endl;
    }

    return 0;
}