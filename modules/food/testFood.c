#include <stdio.h>
#include "food.c"

Word currentWord;

int main(){
    ReadFood_FILE("food.txt");
    return 0;
}