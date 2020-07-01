#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include "AnmeldungenReader.h"

using namespace std;

void AnmeldungenReader::read(std::vector<Anmeldung>& studenten) {

    int mtknr[10000];
    string studiengang[10000];
    int pID_A[10000];

    ifstream csvread;
    int counter1 = 0;
    int counter2 = 0;
    string temp[70000];
    string pversion[10000];
    string pnr[10000];
    string mnr[10000];
    string stg[10000];

    csvread.open("../InputData/Anmeldungen_WS2019_KL.csv", ios::in);

    if(csvread) {
        string s = "";
        while (getline(csvread, s, ';')) {
            temp[counter1] = s;
            //cout << temp[counter1] << "||" << temp[counter1].size() << endl;
            counter1++;
        }
        csvread.close();
    }
    else{
        cerr << "Fehler beim Lesen!" << endl;
    }
//------------------------------mtknr
    for(long int i=6; i<70000; i=i+6){
        mnr[counter2] = temp[i];
        counter2++;
    }
    counter2 = 0;

    for(int i = 0; i < 10000; i++){

        if(mnr[i].size() == 11){
            mnr[i] = mnr[i].substr(5,10);
        }

        if(mnr[i].size() == 12){
            mnr[i] = mnr[i].substr(6,11);
        }

        if(mnr[i].size() == 13){
            mnr[i] = mnr[i].substr(6,12);
        }
    }

    for(int i=0; i<10000; i++){
        if(mnr[i].find("20192")==0){
            mnr[i] = "";
        }
    }

    for(int i=0; i<10000; i++){
        mtknr[i] = atoi(mnr[i].c_str()) ;
    }

//--------------------------------studiengang
    for(long int i=7; i<70000; i=i+6){
        stg[counter2] = temp[i];
        counter2++;
    }
    counter2 = 0;

    for(int i=0; i<10000; i++){
        studiengang[i] = stg[i];
    }
//---------------------------------pID_A
    for(long int i=9; i<70000; i=i+6){
        pnr[counter2] = temp[i];
        //cout << pnr[counter2] << "##"<< temp[i] << endl;
        counter2++;
    }
    counter2 = 0;

    for(long int i=8; i<70000; i=i+6){
        pversion[counter2] = temp[i];
        //cout << pversion[counter2] << "++" << endl;
        counter2++;
    }
    counter2 = 0;
    // ID berechnen
    for(int i=0; i<10000; i++){
        pID_A[i] = atoi(pnr[i].c_str()) - atoi(pversion[i].c_str());
    }

    for(int i = 0; i < 9621; i++){
        studenten.emplace_back(Anmeldung(mtknr[i], studiengang[i],atoi(pnr[i].c_str()),atoi(pversion[i].c_str())));
    }

}
