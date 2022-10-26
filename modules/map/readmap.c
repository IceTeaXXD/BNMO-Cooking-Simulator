#include "../wordmachine/wordmachine.c"
#include "../wordmachine/charmachine.c"
#include "../matrix/matrix.c"
#include <stdio.h>


void displayMap(Matrix m){
        int i, j;
        for (i = 0; i < COL_EFF(m)+2; i ++){
            if(i != COL_EFF(m)+1){
                printf("* ");
            }else{
                printf("*\n");
            }

        }
        for (i = 0; i < ROW_EFF(m); i ++){
            printf("* ");
            for (j = 0; j < COL_EFF(m); j++){
                if (j < COL_EFF(m)-1){
                printf("%d ", MATRIXELMT(m, i,j));
                }else{
                printf("%d", MATRIXELMT(m, i,j));
                
            }
            printf("*\n");
        }
        }
        for (i = 0; i < COL_EFF(m)+2; i ++){
            if(i != COL_EFF(m)+1){
                printf("* ");
            }else{
                printf("*\n");
            }
    }
}            
        

void readMap(Matrix *m){
    
    int M,N;
    STARTWORD_FILE("config.txt");
    N = WordToInt(currentWord);
    ADVWORD();
    M = WordToInt(currentWord);
    ADVNEWLINE();
    
    createMatrix(N, M, &m);
    int i, j;
    for (i=0; i<N; i++){
        for(j=0; j<M; j++){
            if (currentWord.TabWord[j] == '#'){
                MATRIXELMT(*m, i, j) = ' '; 
            }
            else{
                MATRIXELMT(*m, i, j) = currentWord.TabWord[j];
            }
        }
        ADVNEWLINE();
        
    }
    ADV();
}



    

