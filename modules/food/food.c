#include "food.h"
#include "../utility/boolean.h"
#include "../time/time.c"
#include "../wordmachine/wordmachine.c"
#include "../wordmachine/charmachine.c"

void CreateFood(food *x, int id, char name[], TIME expiry, char action[], TIME delivery){
    FoodId(*x) = id;
    FoodName(*x) = name;
    FoodExpiry(*x) = expiry;
    FoodAction(*x) = action;
    FoodDelivery(*x) = delivery;
}

void DisplayFood(food x){
    printf("%d %s ",FoodId(x), FoodName(x));
    TulisTIME(FoodExpiry(x));
    printf(" %s ",FoodAction(x));
    TulisTIME(FoodDelivery(x));
}

void ReadFood_FILE(char filename[]){
    int N;
    STARTWORD_FILE(filename);
    //acquiring N
    N = WordToInt(currentWord);
    ADVWORD();
    int i, j, k, id;
    char name[NMax], action[NMax];
    TIME expiry, delivery;
    printf("Makanan yang terbentuk:\n");
    for (i = 0; i<N; i++){
        food x;
        id = WordToInt(currentWord); //Food ID
        ADVWORD();
        for (j = 0; j < currentWord.Length; j++) {
            name[j] = currentWord.TabWord[j];       //Food Name
        }
        name[j]='\0';
        ADVWORD();
        int DDexp, HHexp, MMexp;
        DDexp = WordToInt(currentWord);
        ADVWORD();
        HHexp = WordToInt(currentWord);
        ADVWORD();
        MMexp = WordToInt(currentWord);
        CreateTime(&expiry, DDexp, HHexp, MMexp);   //Food expiry
        ADVWORD();
        int DDdlv, HHdlv, MMdlv;
        DDdlv = WordToInt(currentWord);
        ADVWORD();
        HHdlv = WordToInt(currentWord);
        ADVWORD();
        MMdlv = WordToInt(currentWord);
        CreateTime(&delivery, DDdlv, HHdlv, MMdlv); //Food delivery
        ADVWORD();
        for (k = 0; k < currentWord.Length; k++) {
            action[k] = currentWord.TabWord[k];       //Food action
        }
        action[k] = '\0';
        ADVWORD();
        CreateFood(&x, id, name, expiry, action, delivery);
        DisplayFood(x);
        printf("\n");
    }
}