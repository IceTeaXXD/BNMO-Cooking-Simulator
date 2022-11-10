/* ADT N-ARY TREE */

#ifndef TREE_H
#define TREE_H

#include "../utility/boolean.h"
#include "../liststatik/liststatik.h"
#include "../wordmachine/charmachine.h"
#include "../wordmachine/wordmachine.h"
#include "../matrix/matrix.h"


/* Definisi Type Data */
typedef struct tNode *addressTree;
typedef struct tNode {
    int data;
    addressTree firstChild;
    addressTree nextSibling;
} Node;

typedef struct {
    addressTree root;
} Tree;


#define Data(P) (P)->data
#define FirstChild(P) (P)->firstChild
#define NextSibling(P) (P)->nextSibling
#define Root(T) (T).root

/* Definisi Pohon : */
/* Pohon kosong : P = Nil */
/* Setiap elemen dengan addressTree P dapat diacu Info(P), FirstChild(P), NextSibling(P) */
/* Elemen terakhir pohon : jika NextSibling(P) = Nil, maka P adalah elemen terakhir pohon */

void CreateTree(Tree *T);

addressTree Alokasi(int X);

void Dealokasi(addressTree P);

void AddChild(addressTree *P, addressTree C);

void AddSibling(addressTree *P, addressTree S);

void printSiblings(addressTree P);

void printChild(addressTree P);

void printTree (addressTree P, int h);

boolean isTreeElmt (addressTree P, int X);

addressTree getAddress (addressTree P, int X);

int Treemachine(char string[], Matrix *m);

void matrixToTree (Matrix m, int N, Tree *T);

addressTree getParent(addressTree root,addressTree C);

#endif