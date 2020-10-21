#include "Bridge.h"


Bridge initBridge()
{
    Bridge b;
    b.giveInfoToFight = false;
    b.giveInfoToTile = false;

    b.ennemyBoat = NULL;

    return b;
}
