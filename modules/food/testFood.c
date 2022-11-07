#include <stdio.h>
#include "food.c"
#include "../prioqueue/prioqueueinv.c"

Word currentWord;

int main(){
    food f1;
    int id;
    char name[50];
    TIME expiry;
    TIME delivery;
    char action[50];
    ListFoodStatik l1;
    Prioqueueinv inv;
    CreateListFoodStatik(&l1);
    MakeEmpty_Prioqueue(&inv, 100);
    ReadFood_FILE("../../cfg/food.txt", &l1);
    printf("List Length: %d\n", listLength_ListFoodStatik(l1));
    int i;
    for (i = 0; i < listLength_ListFoodStatik(l1); i++){
        Enqueue_Prioqueue(&inv, LISTELMT(l1,i));
        DisplayFood(LISTELMT(l1,i));
        printf("\n");
    }
    printf("-----------------\n");
    printList_ListFoodStatik(l1);
    printf("\n");
    printf("-----------------\n");
    Dequeue_Prioqueue(&inv, &f1);
    PrintPrioqueueinv(inv);
    printf("\n");
    DisplayFood(LISTELMT(l1,0));
    Enqueue_Prioqueue(&inv, LISTELMT(l1,0));
    printf("-----------------\n");
    PrintPrioqueueinv(inv);
    //PrintPrioqueueinv(inv);
    //printList_ListFoodStatik(l1);
    // Word k1,k2,k3;
    // int j=0;
    // char name[50];
    // STARTWORD();
    // k1=currentWord;
    // ADVWORD();
    // while (!EndWord) {
    //     k1 = MergeWord(k1,currentWord);
    //     ADVWORD();
    // }
    // printf("k1.length = %d\n", k1.Length);
    // printf("Word : ");
    // for (int i=0;i<k1.Length;i++){
    //     printf("%c", k1.TabWord[i]);
    // }
    // printf("\n");
    // for (int i=0;i<k1.Length;i++){
    //     name[j]=k1.TabWord[i];
    //     j++;
    // }
    // name[j]='\0';
    // printf("Into String: %s\n", name);
    return 0;
}