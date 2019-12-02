#ifndef NAME_H
#define NAME_H

#include  <QString>

using namespace std;

class players	//No.5 correct abstract base class
{
public:
    players()  {/*empty*/}
    ~players() {/*empty*/}
    virtual QString playerName()       {return "NAME";} //Speler met naam
};

#endif // NAME_H

//functie in thegame.cpp geeft random waarde terug die locatie van player-one/two/three teruggeeft
//zo wordt momenteel een random naam gekozen, dit was normaal ook een punt.
