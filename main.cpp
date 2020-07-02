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
#include "DataTypes/TimeSlot.h"

#include <vector>
#include <set>
#include <algorithm>

using namespace std;


int main() {
    cout << "<Raumliste------------------------------------------------------------------>" << endl;
    vector<Raum> raume;
    RaumlisteReader::read(raume);


    for (auto &i : raume) {
        //cout << "Raum: "  << i.getName() << "; Plätze: " << i.getSitzplaetze() << endl;
    }


    cout << "<Prüfungen------------------------------------------------------------------>" << endl;
    vector<Klausur> klausuren;
    vector<Pruefer> pruefer;
    PruefungenReader::read(klausuren, pruefer);


    for (auto &i : klausuren) {
        //cout << "PNR: " << i.getpNR() << "; PVersion: "  << i.getpVersion()  << "; ID: " << i.getID()  << "; pName: "  << i.getpName() << "; Prüfer1: "  << i.getpruefer1() << "; Prüfer2: "  << i.getpruefer2()  << "; Dauer: " << i.getpDauer() <<endl;
    }

    for (auto &i : pruefer) {
        //cout << "Pruefer_ID: " << i.getPruefer() << endl;
    }


    cout << "<Anmeldungen------------------------------------------------------------------>" << endl;
    vector<Anmeldung> anmeldungen;
    AnmeldungenReader::read(anmeldungen);


    for (auto &i : anmeldungen) {
        //cout << "MtkNR: " << i.getMtkNr() << "; Studiengang: " << i.getStg() << "; ID: " << i.getID() << endl;
    }

    //---------------------------------------------------------------------------------------------------------------

    for (auto &i : anmeldungen) {
        bool fehlerAnmeldung = false;
        for (auto &j : klausuren) {
            if (i.getPnr() == j.getpNR() && i.getPVersion() == j.getpVersion()) {
                fehlerAnmeldung = true;
            }
        }
        if (fehlerAnmeldung == false) {
            //cerr << "Fehler bei der Anmeldung vom Student: " << i.getMtkNr() << ". Die Prüfungsversion " << i.getPVersion() << " mit der Nummer "
            //     << i.getPnr() << " wird in diesem Semester nicht angeboten! " << endl;
        }
    }
    //---------------------------------------------------------------------------------------------------------------



    pTage prufungsTage[10];
    TimeSlot timeSlotsTemp[20];

    int pTage_len = sizeof(prufungsTage) / sizeof(prufungsTage[0]);
    int tst_len = sizeof(timeSlotsTemp) / sizeof(timeSlotsTemp[0]);


    //cout<<sizeof(timeSlotsTemp)/sizeof(timeSlotsTemp[0])<<endl;





    for (int a = 0; a < pTage_len; a++) {   //schleife für tage 1-10

        for (int b = 0; b < tst_len; b++) { //schleife für timeslots 1-20

            int count = -1;
            for (auto &i : klausuren) {
                count++;
                cout << "\t--" << klausuren.size() << endl;
                cout << "PNR: " << i.getpNR() << "; PVersion: " << i.getpVersion() << "; pName: " << i.getpName()
                     << "; Prüfer1: " << i.getpruefer1() << "; Prüfer2: " << i.getpruefer2() << "; Dauer: " << i.getpDauer()
                     << endl;


                int tz = 0;
                for (auto &j : anmeldungen) {
                    //Liste der Teilnehmer bekommen
                    if (i.getpNR() == j.getPnr() && i.getpVersion() == j.getPVersion()) {
                        //cout << "--> "<<"MtkNR: " << j.getMtkNr() << "; Studiengang: " << j.getStg() << endl;
                        tz++;
                    }
                }
                //Räume finden die genug plätze haben
                //gKlausur a(i,raume.at(1),teilnehmerzahl,1);
                cout << tz << endl;
                int old_tz = tz;
                vector<Raum> tempRaume;

                for (auto &k : raume) {
                    //Klausuren ohne Teilnehmer rausloschen
                    if (tz == 0) {
                        klausuren.erase(klausuren.begin() + count);
                        break;
                    }
                    //for schleife zum testen ob der raum k frei ist
                    old_tz -= k.getSitzplaetze();
                    tempRaume.emplace_back(k);
                    //emplacter raum soll entprechend des timeslots und der dauer auf nicht ready gestellt werden
                    if (old_tz <= 0) {
                        break;
                    }
                }
                for (auto &x : tempRaume) {
                    //cout << x.getName() << x.getSitzplaetze() << endl;
                }
            }
            break;

        }
        break;
        //cout<<"------" <<endl;
    }




    return 0;
}