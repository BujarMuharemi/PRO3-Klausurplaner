#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    int counter1 = 0;
    int counter2 = 0;
    int counter3 = 0;
    string nummer [1000];
    string plaetze [1000];
    string temp [1000];
    ifstream csvread;

    csvread.open("/home/dejan/PRO3-Klausurplanner/Raumliste.csv", ios::in);

    if(csvread) {
        string s = "";
        //liest csv datei ein und speichert characters in temp solange bis ein "," kommt
        while (getline(csvread, s, ',')) {

            //cout << s << endl;
            temp[counter1] = s;
            counter1++;

            //Wenn der eingelesene String eine Raum-ID war wird der Array nummer mit diesen gefüllt
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
    cout << "--------------------------" << endl;

    //for-schleife dazu da das "Hör-/Lehrsaal" aus den Strings zu löschen -> Sitzplätze herauszufiltern da Sitzplätze + "Hör-/Lehrsaal"
    //zusammen eine Arrayposition in temps besetzt haben z.B. temps[2] = "42"\n"Hör-/Lehrsaal"
    for(int i = 0; i < 1000; i++){
        if(temp[i].size() == 20){
            temp[i] = temp[i].substr(0, 4);
        }
        if(temp[i].size() == 21){
            temp[i] = temp[i].substr(0, 5);
        }
        //cout << temp[i] << endl;
        //cout << nummer[i] << plaetze[i] << endl;
    }
    //Array plaetze wird hier mit den jeweiligen Sitzplätzen befüllt
    for(int i = 2; i < 1000; i = i+2){
        plaetze[counter3] = temp[i];
        counter3++;
    }
    //"Fertige" Ausgabe
    for(int i = 0; i < 54; i++){
        cout << "Raum: " << nummer[i] << "; Sitzplätze: " << plaetze[i] << endl;
    }

    return 0;
}