#ifndef NAME_H
#define NAME_H

#include  <QString>

using namespace std;

class players
{
public:
    players()  {/*empty*/}
    ~players() {/*empty*/}
    virtual QString playerName()       {return "NAME";} //Speler met naam
};

#endif // NAME_H

//functie in thegame.cpp geeft random waarde terug die locatie van player-one/two/three teruggeeft
//zo wordt momenteel een random naam gekozen
