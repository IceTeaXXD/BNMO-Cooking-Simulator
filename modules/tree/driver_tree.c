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
    return 0;
}