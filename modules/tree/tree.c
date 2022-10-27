#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/*KONSTRUKTOR*/
void CreateTree(Tree *T){
    (*T).root = NULL;
}

/* *** Manajemen Memory *** */
address Alokasi(int X){
    address P = (address) malloc(sizeof(Node));
    if(P != NULL){
        Data(P) = X;
        FirstChild(P) = NULL;
        NextSibling(P) = NULL;
    }
    return P;
}

void Dealokasi(address P){
    free(P);
}


void AddChild(address *P, address C){
    if(*P == NULL){
        *P = C;
    }else{
        address Q = *P;
        while(FirstChild(Q) != NULL){
            Q = FirstChild(Q);
        }
        FirstChild(Q) = C;
    }
}

void AddSibling(address *P, address S){
    if(*P == NULL){
        *P = S;
    }else{
        address Q = *P;
        while(NextSibling(Q) != NULL){
            Q = NextSibling(Q);
        }
        NextSibling(Q) = S;
    }
}

void printSiblings(address P){
    if(P != NULL){
        printf("%d ", Data(P));
        printSiblings(NextSibling(P));
    }
}

void printChild(address P){
    if(P != NULL){
        printf("%d ", Data(P));
        printChild(FirstChild(P));
        printSiblings(NextSibling(P));
    }
}

void printTree (address P, int h){
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

boolean isTreeElmt (address P, int X){
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

// int to address
address toAddress (address P, int X){
    if(P != NULL){
        if(Data(P) == X){
            return P;
        }else{
            address Q = toAddress(FirstChild(P), X);
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