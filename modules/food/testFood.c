#include <stdio.h>
#include "food.c"

Word currentWord;

int main(){
    food f1;
    int id;
    char name[50];
    TIME expiry;
    TIME delivery;
    char action[50];
    //CreateTime(&expiry, 1,1,1);
    //CreateTime(&delivery, 1,1,1);
    //CreateFood(&f1, id, name, expiry, action, delivery);
    ListFoodStatik l1;
    CreateListFoodStatik(&l1);
    ReadFood_FILE("food.txt", &l1);
    //printList_ListFoodStatik(l1);
    //DisplayFood((l1).contents[(0)]);
    //DisplayFood(f1);
    return 0;
}