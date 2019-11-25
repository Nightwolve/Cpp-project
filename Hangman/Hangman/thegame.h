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

#define fileLocation "C://Users//Administrator//Desktop//Hangman//lastword.txt"

#include "playerone.h"
#include "playertwo.h"
#include "playerthree.h"

using namespace std;

class Thegame
{
private: //kunnen enkel in class Thegame te gebruiken
    const int maxTries = 7;
    int tries=7;
    uint showncounter;
    int choice=0;//Keuze uit menu
    int loop=1;// variabele voor de loop
    char ans='n';//originele conditie van de while loop, basismenu met instructies
    string usersWord;// Geheim woord dat gebruiker invoerd
    string topic;// Onderwerp van game "name"
    Thegame* obj = nullptr;
    string response;// Geheim woord wordt opgeslagen in deze string
    string shown="";// Toon gebruiker hoe ver ze zijn gekomen met gokken
    void addTries();
    void storetheword(string HangmanWord);// Functie die woord in privé variabele opslaat zodat dit niet bekeken kan worden.
    void tryLetters();// Functie onthoud reeds gekozen letters
    void resetword();// Functie onthoud woord voor eventuele volgende rondes
    void hangmandrawing();// Functie voor het tekenen van Hangman
    void completehangman();
    QString getName();

public: //openbare functies, overal te gebruiken
    Thegame();
    ~Thegame();
    void game();
    inline QString name() {return Thegame().getName();}
};

#endif // THEGAME_H
