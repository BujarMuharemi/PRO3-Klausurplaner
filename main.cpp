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

using namespace std;

int main(){
//-------------------------------------------------------------------RaumlisteReader
    vector<Raum> raume;
    RaumlisteReader::read(raume);

    cout << "<Raumliste------------------------------------------------------------------>" << endl;

    for(auto & i : raume){
        cout << i.getName() << "--" << i.getSitzplaetze() << endl;
    }

//--------------------------------------------------------------------PrüfungenReader
    int pID[1000];
    string modul[1000];
    int pruefer1[1000];
    int pruefer2[1000];
    int dauer[1000];

    cout << "<Prüfungen------------------------------------------------------------------>" << endl;

    PruefungenReader::read(pID, modul, pruefer1, pruefer2, dauer);

    for(int i = 0; i < 544; i++){
        //cout<< "pID: " << pID[i]  << "; modul: " << modul[i] << "; pruefer1: " << pruefer1[i] << "; pruefer2: " << pruefer2[i] << "; dauer: " << dauer[i] << endl;
    }
//--------------------------------------------------------------------AnmeldungenReader
    int mtknr[10000];
    string studiengang[10000];
    int pID_A[10000];

    AnmeldungenReader::read(mtknr, studiengang, pID_A);

    cout << "<Anmeldungen------------------------------------------------------------------>" << endl;

    for(int i=0; i<9621; i++){
        //cout << "pID-A: " << pID_A[i] << "; studiengang: " << studiengang[i] <<"; mtknr: " << mtknr[i] <<endl;
    }

    return 0;
}