#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include "RaumlisteReader.h"

using namespace std;

void RaumlisteReader::read(string nummer[], int plaetzeint[]) {
    int counter1 = 0;
    int counter2 = 0;
    int counter3 = 0;
    string plaetze [1000];
    string temp [1000];
    string toint;
    ifstream csvread;

    csvread.open("../InputData/Raumliste.csv", ios::in);

    if(csvread) {
        string s = "";
        while (getline(csvread, s, ',')) {

            temp[counter1] = s;
            counter1++;

            if(s.find("/") == 2){
                nummer[counter2] = s;
                counter2++;
            }
        }
        csvread.close();
    }
    else{
        cerr << "Fehler beim Lesen!" << endl;
    }

    for(int i = 0; i < 1000; i++){
        if(temp[i].size() == 20){
            temp[i] = temp[i].substr(1, 3);
        }
        if(temp[i].size() == 21){
            temp[i] = temp[i].substr(1, 4);
        }
        if(temp[i].size() == 5){
            temp[i] = temp[i].substr(1, 3);
        }
        if(temp[i].size() == 6){
            temp[i] = temp[i].substr(1, 4);
        }

    }

    for(int i = 2; i < 1000; i = i+2){
        plaetze[counter3] = temp[i];
        counter3++;
    }

    for(int i=0; i<1000; i++){
        plaetzeint[i] = atoi(plaetze[i].c_str());
    }

    for(int i=0; i<1000; i++){
        plaetzeint[i] = plaetzeint[i]/4;

    }
}
