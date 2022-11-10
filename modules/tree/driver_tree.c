#include <stdio.h>
#include <stdlib.h>
#include "tree.c"

int main()
{   
    Matrix m;
    createMatrix(100,100,&m);
    int N = Treemachine("../../cfg/resep.txt",&m);
    Tree T;
    matrixToTree(m,N,&T);
    printTree(T.root,0);
    addressTree P,C;
    C = getAddress(T.root,7);
    if (C != NULL){
        printf("C : %d\n",Data(C));
    }
    else{
        printf("C Null\n");
    }
    P = getParent(T.root,C);
    if (P != NULL){
        printf("Parent of C : %d\n",Data(P));
    }
    else{
        printf("P Null\n");
    }
    return 0;
}