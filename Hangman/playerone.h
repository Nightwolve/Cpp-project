#ifndef PLAYERONE_H
#define PLAYERONE_H

#include "players.h"

using namespace std;

class playerone: public players
{
public:
    playerone(){}
    ~playerone(){}
    QString         playerName()          {return "player1";} // naam player1 -> geef naam in na return

};

#endif // PLAYERONE_H
