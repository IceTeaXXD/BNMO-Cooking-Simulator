#include "../utility/boolean.h"
#include "../wordmachine/wordmachine.c"
#include "../wordmachine/charmachine.c"
#include "../matrix/matrix.c"
Word currentWord;

int Treemachine(char string[], Matrix *m){
    int count = 0;
    int count1 = 1;
    int tempint = 1;
    int itemp = 0;
    int k = 0, j = 0;
    STARTWORD_FILE(string);
    tempint = WordToInt(currentWord);
    ADVWORD();
    while (count != tempint){
        if (count1 == 2){
            itemp = WordToInt(currentWord) + 2;
        }
        MATRIXELMT(*m,k,j) = WordToInt(currentWord);
        j++;
        if (count1 == itemp){
            k++;
            j = 0;
            count1 = 0;
            count++;
        }
        count1++;
        if (count != tempint){
            ADVWORD();
        }
    }
    return tempint;
}