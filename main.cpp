#include <iostream>
#include <fstream>
#include <string>

#include "DataTypes/Raum.h"
#include "DataTypes/Anmeldung.h"
#include "DataTypes/Pruefer.h"
#include "DataTypes/Klausur.h"
#include "Readers/RaumlisteReader.h"
#include "Readers/PruefungenReader.h"
#include "Readers/AnmeldungenReader.h"
#include "DataTypes/pTage.h"
#include "DataTypes/gKlausur.h"

#include <vector>
#include <set>
#include <algorithm>

using namespace std;


int main(){
    cout << "<Raumliste------------------------------------------------------------------>" << endl;
    vector<Raum> raume;
    RaumlisteReader::read(raume);

    /*
    for(auto & i : raume){
        cout << "Raum: "  << i.getName() << "; Plätze: " << i.getSitzplaetze() << endl;
    }
     */


    cout << "<Prüfungen------------------------------------------------------------------>" << endl;
    vector<Klausur> klausuren;
    vector<Pruefer> pruefer;
    PruefungenReader::read(klausuren, pruefer);


    for(auto & i : klausuren){
        //cout << "PNR: " << i.getpNR() << "; PVersion: "  << i.getpVersion()  << "; ID: " << i.getID()  << "; pName: "  << i.getpName() << "; Prüfer1: "  << i.getpruefer1() << "; Prüfer2: "  << i.getpruefer2()  << "; Dauer: " << i.getpDauer() <<endl;
    }

    for(auto & i : pruefer){
        //cout << "Pruefer_ID: " << i.getPruefer() << endl;
    }


    cout << "<Anmeldungen------------------------------------------------------------------>" << endl;
    vector<Anmeldung> studenten;
    AnmeldungenReader::read(studenten);


    for(auto & i : studenten){
        //cout << "MtkNR: " << i.getMtkNr() << "; Studiengang: " << i.getStg() << "; ID: " << i.getID() << endl;
    }

    pTage prufungsTage[10];

    for(auto & i : klausuren){
        cout << "PNR: " << i.getpNR() << "; PVersion: "  << i.getpVersion()   << "; pName: "  << i.getpName() << "; Prüfer1: "  << i.getpruefer1() << "; Prüfer2: "  << i.getpruefer2()  << "; Dauer: " << i.getpDauer() <<endl;


        int t=0;
        for(auto & j : studenten){
            //Liste der Teilnehmer bekommen
            if(i.getpNR()==j.getPnr() && i.getpVersion()==j.getPVersion()){
                cout << "--> "<<"MtkNR: " << j.getMtkNr() << "; Studiengang: " << j.getStg() << "; ID: "  << endl;
                t++;
            }
        }
        gKlausur a(i,raume.at(1),t,1);
        cout << a.getTeilnehmerZahl()<<endl;


    }







    return 0;
}