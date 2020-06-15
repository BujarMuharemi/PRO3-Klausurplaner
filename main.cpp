#include <iostream>
#include <fstream>
#include <string>
#include "DataTypes/Raum.h"
#include "DataTypes/Student.h"
#include "DataTypes/Pruefer.h"
#include "DataTypes/Klausur.h"


using namespace std;

int main(){

    Student b(123456,"IF",234234,234234,"KL","Klausur",20192);
    Raum a("asdf",4);
    Pruefer pPaar(6317,452);
    Pruefer p1(666);

    Klausur k("AB",141,1030,"Technik Grundlagen",pPaar,210,"KL",20201);

    cout << "Prüfer parr: 1:" << pPaar.getPruefer1()<< " 2:"<<pPaar.getPruefer2()<<endl;

    cout << "Hello World" << a.getSitzplaetze() << endl;

    cout << "ID: " << k.getID();

    return 0;
}