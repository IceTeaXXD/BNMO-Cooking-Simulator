#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
// #include "../liststatik/liststatik.c"
// #include "../wordmachine/charmachine.c"
// #include "../wordmachine/wordmachine.c"
// #include "../matrix/matrix.c"

/*KONSTRUKTOR*/
void CreateTree(Tree *T){
    (*T).root = NULL;
}

/* *** Manajemen Memory *** */
addressTree Alokasi(int X){
    addressTree P = (addressTree) malloc(sizeof(Node));
    if(P != NULL){
        Data(P) = X;
        FirstChild(P) = NULL;
        NextSibling(P) = NULL;
    }
    return P;
}

void Dealokasi(addressTree P){
    free(P);
}


void AddChild(addressTree *P, addressTree C){
    if(*P == NULL){
        *P = C;
    }else{
        addressTree Q = *P;
        while(FirstChild(Q) != NULL){
            Q = FirstChild(Q);
        }
        FirstChild(Q) = C;
    }
}

void AddSibling(addressTree *P, addressTree S){
    if(*P == NULL){
        *P = S;
    }else{
        addressTree Q = *P;
        while(NextSibling(Q) != NULL){
            Q = NextSibling(Q);
        }
        NextSibling(Q) = S;
    }
}

void printSiblings(addressTree P){
    if(P != NULL){
        printf("%d ", Data(P));
        printSiblings(NextSibling(P));
    }
}

void printChild(addressTree P){
    if(P != NULL){
        printf("%d ", Data(P));
        printChild(FirstChild(P));
        printSiblings(NextSibling(P));
    }
}

void printTree (addressTree P, int h){
    if(P != NULL){
        int i;
        for(i = 0; i < h; i++){
            printf("    ");
        }
        printf("%d\n", Data(P));
        printTree(FirstChild(P), h+1);
        printTree(NextSibling(P), h);
    }
}

boolean isTreeElmt (addressTree P, int X){
    if(P != NULL){
        if(Data(P) == X){
            return true;
        }else{
            return isTreeElmt(FirstChild(P), X) || isTreeElmt(NextSibling(P), X);
        }
    }else{
        return false;
    }
}

// int to addressTree
addressTree toAddress (addressTree P, int X){
    if(P != NULL){
        if(Data(P) == X){
            return P;
        }else{
            addressTree Q = toAddress(FirstChild(P), X);
            if(Q != NULL){
                return Q;
            }else{
                return toAddress(NextSibling(P), X);
            }
        }
    }else{
        return NULL;
    }
}

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

void matrixToTree (Matrix m, int N, Tree *T){
    int i,j,k,found,temp;
    addressTree P[N];
    addressTree PPrev;
    addressTree PNow;

    for (i = 0 ; i < N ; i ++){
        P[i] = Alokasi(MATRIXELMT(m,i,0));
    }

    (*T).root = P[N-1];

    for (i = 0 ; i < N ; i++){
        temp = 0;
        for (j = 0 ; j < MATRIXELMT(m,i,1) ; j++){
            // check if m[i][j+2] exists in P
            found = 0;
            k = 0;
            while (k < N && !found){
                if (MATRIXELMT(m,i,j+2) == Data(P[k])){
                    found = 1;
                }
                k++;
            }
            if (!found){
                PNow = Alokasi(MATRIXELMT(m,i,j+2));
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
}