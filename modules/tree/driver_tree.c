#include <stdio.h>
#include <stdlib.h>
#include "tree.c"
//#include "../food/food.c"

int main()
{   
    Matrix m;
    ListTreeStatik lt;
    CreateListTreeStatik(&lt);
    createMatrix(100,100,&m);
    int N = Treemachine("../../cfg/resep.txt",&m);
    Tree T,T1;
    matrixToTree(m,N,&T);
    insertLast_ListTreeStatik(&lt, T);
    N = Treemachine("../../cfg/resepOld.txt",&m);
    matrixToTree(m,N,&T);
    //printTree(T.root,0);
    //printTree(T1.root,0);
    insertLast_ListTreeStatik(&lt, T);
    // addressTree P,C;
    // C = getAddress(T.root,7);
    // if (C != NULL){
    //     printf("C : %d\n",Data(C));
    // }
    // else{
    //     printf("C Null\n");
    // }
    // P = getParent(T.root,C);
    // if (P != NULL){
    //     printf("Parent of C : %d\n",Data(P));
    // }
    // else{
    //     printf("P Null\n");
    // }

    // return 0;
    printList_ListTreeStatik(lt);
}