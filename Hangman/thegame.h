#ifndef THEGAME_H
#define THEGAME_H

#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <QList>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <windows.h>

#define fileLocation "C://Users//Bart//Desktop//Hangman//lastword.txt"

#include "playerone.h"
#include "playertwo.h"
#include "playerthree.h"

using namespace std;
//No. 21 everything in one or more self-made namespace(s)
//No. 22 maintanability by good function naming and/or comments everywhere
//No. 23 seperate header files --> zie code in totaal
//no. 40 using the best suited type on a lot of places

class Thegame               //No. 2 useful class(obvious reasons)
{
private:                    //No. 3 usefull encapsulation --> kunnen enkel in class Thegame te gebruiken // no. 18 correct protections???
    int maxTries = 7; //No. 10 at least 2 specific constructors$
    int tries=7;        //No. 15 default values in function definition$$
    uint showncounter;      //No. 41 correctly using const in almost all places
    int choice=0;   //No. 16 useful member variabel
    int loop=1; // variabele voor de loop
    char ans='n';   //No. 24 2 unsigned chars or other better usage of memory efficient type / originele conditie van de while loop, basismenu met instructies
    string usersWord;   // Geheim woord dat gebruiker invoerd
    string topic;   // Onderwerp van game "name"
    Thegame* obj = nullptr; //No. 27 useful pointer declaration and usage // No. 44 useful usage of nullptr
    string response;    // Geheim woord wordt opgeslagen in deze string
    string shown="";    // Toon gebruiker hoe ver ze zijn gekomen met gokken
    void addTries();    //No. 9 at least 2 default constructors
    void storetheword(string HangmanWord);  // Functie die woord in privé variabele opslaat zodat dit niet bekeken kan worden.
    void tryLetters();  // Functie onthoud reeds gekozen letters
    void resetword();   // Functie onthoud woord voor eventuele volgende rondes
    void hangmandrawing();  // Functie voor het tekenen van Hangman
    void completehangman();
    QString getName();  //No. 33 usefull Qt class

public:     //openbare functies, overal te gebruiken
    Thegame();
    ~Thegame(); //No. 12 at least 2 destructors
    void game();
    inline const QString name() {return Thegame().getName();} //No. 14 useful member function // No. 42 correct useage of inline function
};

#endif // THEGAME_H
