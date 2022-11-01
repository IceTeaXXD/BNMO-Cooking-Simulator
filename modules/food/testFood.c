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
    ListFoodStatik l1;
    CreateListFoodStatik(&l1);
    ReadFood_FILE("../../cfg/food.txt", &l1);
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