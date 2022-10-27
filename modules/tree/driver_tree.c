#include <stdio.h>
#include <stdlib.h>
#include "tree.c"
#include "../listdin/listdin.c"
#include "../matrix/matrix.c"

int main()
{

    Tree T3;
    CreateTree(&T3);

    int N = 7;
    int i,j,k,found,temp;
    int L2[] = {10,1,15};
    int L3[] = {6,3,10,11,12};
    int L4[] = {4,2,6,7};
    int L5[] = {2,2,4,5};
    int L6[] = {5,2,8,9};
    int L7[] = {9,2,13,14};
    int L8[] = {0,3,1,2,3};
    int *L[] = {L2,L3,L4,L5,L6,L7,L8};
    address P[7];
    address PPrev;
    address PNow;
    for (i = 0 ; i < N ; i++){
        P[i] = Alokasi(L[i][0]);
    }

    T3.root = P[6];

    for (i = 0 ;  i < N ; i++){
        temp = 0;
        for (j = 0 ; j < L[i][1] ; j++){
            // check if L[i][j+2] exists in P
            found = 0;
            k = 0;
            while (k < N && !found){
                if (L[i][j+2] == Data(P[k])){
                    found = 1;
                }
                k++;
            }
            if (!found){
                PNow = Alokasi(L[i][j+2]);
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
    return 0;
}