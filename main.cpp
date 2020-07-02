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
#include "DataTypes/Pruefer.h"

#include <vector>
#include <set>
#include <algorithm>

using namespace std;


void resetEverything( vector<Raum> raume,vector<Pruefer> pruefer,   vector<Anmeldung> anmeldungen){
    cout<<"\n_-------------------\n"<<endl;
    for (auto &i : raume) {
        i.resetReady();
    }

    for (auto &i : pruefer) {
        i.resetReady();
    }

    for (auto &i : anmeldungen) {
        i.resetReady();
    }

}


int main() {
    cout << "<Raumliste------------------------------------------------------------------>" << endl;
    vector<Raum> raume;
    RaumlisteReader::read(raume);


    for (auto &i : raume) {
        i.resetReady();
        //cout << "Raum: "  << i.getName() << "; Plätze: " << i.getSitzplaetze() << endl;
    }


    cout << "<Prüfungen------------------------------------------------------------------>" << endl;
    vector<Klausur> klausuren;
    vector<Pruefer> pruefer;
    PruefungenReader::read(klausuren, pruefer);


    for (auto &i : klausuren) {
        if(i.getpDauer()==45){
            i.setPDauer(2);
        }else{
            i.setPDauer(i.getpDauer()/30);
        }
        //cout << "PNR: " << i.getpNR() << "; PVersion: "  << i.getpVersion()  << "; ID: " << i.getID()  << "; pName: "  << i.getpName() << "; Prüfer1: "  << i.getpruefer1() << "; Prüfer2: "  << i.getpruefer2()  << "; Dauer: " << i.getpDauer() <<endl;
    }

    for (auto &i : pruefer) {
        i.resetReady();
        //cout << "Pruefer_ID: " << i.getPruefer() << endl;
    }


    cout << "<Anmeldungen------------------------------------------------------------------>" << endl;
    vector<Anmeldung> anmeldungen;
    AnmeldungenReader::read(anmeldungen);


    for (auto &i : anmeldungen) {
        i.resetReady();
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
    //---------------------------------------------------------------------------------------------------------------
    //---------------------------------------------------------------------------------------------------------------

    pTage prufungsTage[10];
    TimeSlot timeSlotsTemp[20];


    int pTage_len = sizeof(prufungsTage) / sizeof(prufungsTage[0]);
    int tst_len = sizeof(timeSlotsTemp) / sizeof(timeSlotsTemp[0]);

    bool isPlanned = false;

    //cout<<sizeof(timeSlotsTemp)/sizeof(timeSlotsTemp[0])<<endl;

    //cout<<"__________________"<< pruefer[0].getIsReady(0,3)<<endl;

    //gKlausur gk();
    //timeSlotsTemp[0].geplanteKlausurListe.emplace_back(gk);

    for (int a = 0; a < pTage_len; a++) {   //schleife für tage 1-10
        cout << "_-_> Tag: "<<a<<endl;

        for (int b = 0; b < tst_len-7; b++) { //schleife für timeslots 1-20
        vector<gKlausur> tempPlan;
            //vector<gKlausur> plan = timeSlotsTemp[b].getGeplanteKlausurListe();

            int count = -1;
            cout << "Timelost:"<< b <<"\nDavor: klausurenSize:_--------"<<klausuren.size() <<endl;
            for (auto &i : klausuren) {
                count++;
                //cout << "\t--" << klausuren.size() << endl;
                /*
                cout << "PNR: " << i.getpNR() << "; PVersion: " << i.getpVersion() << "; pName: " << i.getpName()
                     << "; Prüfer1: " << i.getpruefer1() << "; Prüfer2: " << i.getpruefer2() << "; Dauer: " << i.getpDauer()*30
                     << endl;*/


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
                //cout << tz << endl;
                int old_tz = tz;
                vector<Raum> tempRaume;

                for (auto &k : raume) {
                    //Klausuren ohne Teilnehmer rausloschen

                    if (tz == 0) {
                        klausuren.erase(klausuren.begin() + count);
                        break;
                    }

                    //for schleife zum testen ob der raum k frei ist
                    //old_tz -= k.getSitzplaetze();
                    //tempRaume.emplace_back(k);

                    //cout<<"B:" << b<<"\t kalusur dauer::"<<i.getpDauer()<<endl;


                    if(k.getIsReady(b,i.getpDauer())){

                        Pruefer tempPruefer(1);


                        for (auto &l : pruefer){

                            if(l.getPruefer()==i.getpruefer1()){
                                tempPruefer=l.getPruefer();
                                tempPruefer.resetReady();
                                l=tempPruefer;
                                //cout <<"-------tempPruefer.getisready:::" << tempPruefer.getIsReady(b,i.getpDauer()) <<endl;

                                if(tempPruefer.getIsReady(b,i.getpDauer())){
                                   //cout<<"Prufer: " <<tempPruefer.getPruefer()<<endl;

                                    k.setIsReady(b,i.getpDauer());
                                    l.setIsReady(b,i.getpDauer());
                                    tempRaume.emplace_back(k);
                                    old_tz -= k.getSitzplaetze();
                                    isPlanned = true;
                                    break;
                                }

                            }
                        }
                    }else{
                        //cout<<"Raum ist nicht frei"<<endl;

                    }

                    //emplacter raum soll entprechend des timeslots und der dauer auf nicht ready gestellt werden
                    if (old_tz <= 0) {
                        break;
                    }


                }
                for (auto &x : tempRaume) {
                   //cout << x.getName() << " "<< x.getSitzplaetze() << endl;
                }
                if(isPlanned) {
                    gKlausur geplant(i, tempRaume, tz, b);
                    tempPlan.emplace_back(geplant);
                    cout << "# GeplannteStartZeit" << geplant.getStartZeit() << "      Teilnehmerzahl " << geplant.getTeilnehmerZahl() << endl;
                    isPlanned = false;
                    klausuren.erase(klausuren.begin() + count);
                    //cout << "%%%%%%%% eine klausur geloscht"<<endl;
                    cout << "PNR: " << i.getpNR() << "; PVersion: " << i.getpVersion() << "; pName: " << i.getpName()
                         << "; Prüfer1: " << i.getpruefer1() << "; Prüfer2: " << i.getpruefer2() << "; Dauer: " << i.getpDauer()*30
                         << endl;
                }

            }
            cout << "Danach: klausurenSize:_--------"<<klausuren.size() <<endl;
            timeSlotsTemp[b].setGeplanteKlausurListe(tempPlan);
            //cout << "__________"<<timeSlotsTemp[b].getGeplanteKlausurListe().at(13).getTeilnehmerZahl()<<endl;
            cout << "\n AnzahlgeplanteKlausuren:"<<tempPlan.size()<<endl;
            if(tempPlan.size()>20){
                cout << "µµµµµµµµµµµµµµ";
            }



            //break;

        }
        for (auto &i : raume) {
            i.resetReady();
        }

        for (auto &i : pruefer) {
            i.resetReady();
        }

        for (auto &i : anmeldungen) {
            i.resetReady();
        }
        //break;

    }




    return 0;
}