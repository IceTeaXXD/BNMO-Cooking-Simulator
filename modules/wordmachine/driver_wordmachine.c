#include <stdio.h>
#include "wordmachine.h"
#include "wordmachine.c"

int main() {
    int i;

    //input word dari file
    START_FILE("test.txt");
    while (!EndWord) {
        for (i = 0; i < currentWord.Length; i++) {
            printf("%c", currentWord.TabWord[i]);
        }
        printf("\n");
        ADVWORD(); 
    }
    
    //input word dari keyboard
    STARTWORD();
    while (!EndWord) {
        printf("\"");
        for (i = 0; i < currentWord.Length; i++) {
            printf("%c", currentWord.TabWord[i]);
        }
        printf("\"");
        printf("\n");
        ADVWORD();
    }

    //input sentence
    STARTSENTENCE();
    while (!EndWord) {
        printf("\"");
        for (i = 0; i < currentWord.Length; i++) {
            printf("%c", currentWord.TabWord[i]);
        }
        printf("\"");
        printf("\n");
    }
}