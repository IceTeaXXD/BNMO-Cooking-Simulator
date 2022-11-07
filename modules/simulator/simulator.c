#include "simulator.h"
#include "../prioqueue/prioqueueinv.h"

void CreatePlayer(player *p){
    USERNAME(*p)="\0";
    CreatePoint(&p->loc,0,0);
    MakeEmpty_Prioqueue(&p->inventory, 1000);
}