#include "../wordmachine/wordmachine.c"
#include "../wordmachine/charmachine.c"
#include "../matrix/matrix.c"
#include <stdio.h>

char IntToMap(char c){
    if (c == 1){
        return ' ';
    }
    else if(c == 2){
        return 'S';
    }
    else if(c == 3){
        return 'T';
    }
    else if(c == 4){
        return 'M';
    }
    else if(c == 5){
        return 'C';
    }
    else if(c == 6){
        return 'F';
    }
    else if(c == 7){
        return 'B';
    }
    else if(c == 8){
        return 'X';
    }
}

void displayMap(Matrix m){
    int i,j;
    for (i = 0 ; i < COL_EFF(m)+2 ; i++){
        if (i != COL_EFF(m)+1){
            printf("* ");
        }else{
            printf("*\n");
        }
    }

    for (i = 0 ; i < ROW_EFF(m) ; i++){
        printf("* ");
        for (j = 0 ; j < COL_EFF(m) ; j++){
            if (j < COL_EFF(m)){
                printf("%c ",IntToMap(MATRIXELMT(m,i,j)));
            }else{
                printf("%d",IntToMap(MATRIXELMT(m,i,j)));
            }
        }
        printf("*\n");
    }

    for (i = 0 ; i < COL_EFF(m)+2 ; i++){
        if (i != COL_EFF(m)+1){
            printf("* ");
        }else{
            printf("*\n");
        }
    }
}            
        
void readMap(Matrix *m){
    // read file
    int i,j,k;
    STARTWORD_FILE("../../cfg/map.txt");
    // the first line is number of row and cols
    int row,col;
    row = WordToInt(currentWord);
    ADVWORD();
    col = WordToInt(currentWord);
    ADVWORD();

    // create matrix
    createMatrix(row,col,m);

    for (i = 0 ; i < row ; i++){
        for (j = 1; j <= col ; j++){
            if (currentWord.TabWord[j] == '#'){
                MATRIXELMT(*m,i,j-1) = 1;
            }else if (currentWord.TabWord[j] == 'S'){
                MATRIXELMT(*m,i,j-1) = 2;
            }else if (currentWord.TabWord[j] == 'T'){
                MATRIXELMT(*m,i,j-1) = 3;
            }else if (currentWord.TabWord[j] == 'M'){
                MATRIXELMT(*m,i,j-1) = 4;
            }else if (currentWord.TabWord[j] == 'C'){
                MATRIXELMT(*m,i,j-1) = 5;
            }else if (currentWord.TabWord[j] == 'F'){
                MATRIXELMT(*m,i,j-1) = 6;
            }else if (currentWord.TabWord[j] == 'B'){
                MATRIXELMT(*m,i,j-1) = 7;
            }else if (currentWord.TabWord[j] == 'X'){
                MATRIXELMT(*m,i,j-1) = 8;
            }
        }
        if (i < row-1){
            ADVWORD();
        }
    }
}

int main(){
    Matrix m;
    readMap(&m);
    displayMap(m);
    return 0;
}