#ifndef PLAYERTWO_H
#define PLAYERTWO_H

#include "players.h"

using namespace std;

class playertwo: public players
{
public:
    playertwo(){}
    ~playertwo(){}
    QString         playerName()          {return "player2";} //Player2 met naam "Player2"

};

#endif // PLAYERTWO_H
