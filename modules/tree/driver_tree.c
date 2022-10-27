#include <stdio.h>
#include <stdlib.h>
#include "tree.c"
#include "../matrix/matrix.c"

int main()
{   
    Matrix L;
    createMatrix(100, 100, &L);
    int L2[] = {10,1,15};
    int L3[] = {6,3,10,11,12};
    int L4[] = {4,2,6,7};
    int L5[] = {2,2,4,5};
    int L6[] = {5,2,8,9};
    int L7[] = {9,2,13,14};
    int L8[] = {0,3,1,2,3};
    
    // put l2 to l8 in L
    int i,j;
    for (i = 0 ; i < 7 ; i ++){
        for (j = 0 ; j < L.rowEff ; j ++){
            if (i == 0){
                MATRIXELMT(L,i,j) = L2[j];
            }
            else if (i == 1){
                MATRIXELMT(L,i,j) = L3[j];
            }
            else if (i == 2){
                MATRIXELMT(L,i,j) = L4[j];
            }
            else if (i == 3){
                MATRIXELMT(L,i,j) = L5[j];
            }
            else if (i == 4){
                MATRIXELMT(L,i,j) = L6[j];
            }
            else if (i == 5){
                MATRIXELMT(L,i,j) = L7[j];
            }
            else if (i == 6){
                MATRIXELMT(L,i,j) = L8[j];
            }
        }
    }
    Tree T3;
    CreateTree(&T3);

    int N = 7;
    int k,found,temp;
    // int i,j,k,found,temp;
    // int L2[] = {10,1,15};
    // int L3[] = {6,3,10,11,12};
    // int L4[] = {4,2,6,7};
    // int L5[] = {2,2,4,5};
    // int L6[] = {5,2,8,9};
    // int L7[] = {9,2,13,14};
    // int L8[] = {0,3,1,2,3};
    // int *L[] = {L2,L3,L4,L5,L6,L7,L8};
    addressTree P[7];
    addressTree PPrev;
    addressTree PNow;
    for (i = 0 ; i < N ; i++){
        P[i] = Alokasi(MATRIXELMT(L,i,0));
    }

    T3.root = P[6];

    for (i = 0 ;  i < N ; i++){
        temp = 0;
        for (j = 0 ; j < MATRIXELMT(L,i,1) ; j++){
            // check if L[i][j+2] exists in P
            found = 0;
            k = 0;
            while (k < N && !found){
                if (MATRIXELMT(L,i,j+2) == Data(P[k])){
                    found = 1;
                }
                k++;
            }
            if (!found){
                PNow = Alokasi(MATRIXELMT(L,i,j+2));
            } else {
                PNow = P[k-1];
            }

            if (temp == 0){
                AddChild(&P[i], PNow);
                temp = 1;
            }
            else{
                AddSibling(&PPrev, PNow);
            }
            PPrev = PNow;
        }
    }
    displayMatrix(L);
    printTree(T3.root, 0);

    return 0;
}