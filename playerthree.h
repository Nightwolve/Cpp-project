#ifndef PLAYERTHREE_H
#define PLAYERTHREE_H

#include <players.h>

using namespace std;

class playerthree: public players
{
public:
    playerthree(){}
    ~playerthree(){}
    QString         playerName()          {return "player3";} //Speler 3 met als naam "Player3" op dit moment

};

#endif // PLAYERTHREE_H
