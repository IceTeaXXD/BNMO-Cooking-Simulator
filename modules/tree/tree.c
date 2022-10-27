#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

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