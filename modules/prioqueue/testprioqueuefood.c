#include <stdio.h>
#include "prioqueuefood.c"

int main(){
    PrioQueueFood q;
    ListFoodStatik l;
    int i;
    CreateListFoodStatik(&l);
    ReadFood_FILE("../../cfg/food.txt", &l);
    MakeEmpty_Prioqueue(&q,10);
    for (i = 0; i<listLength_ListFoodStatik(l);i++){
        Enqueue_Prioqueue(&q,LISTELMT(l,i));
    }
    PrintPrioQueueFood(q);
    return 0;
}