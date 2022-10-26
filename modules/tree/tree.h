/* ADT N-ARY TREE */

#ifndef TREE_H
#define TREE_H

#include "../utility/boolean.h"
#include "../liststatik/liststatik.h"
#include "../listdin/listdin.h"

#define Nil NULL

/* Definisi Type */
typedef struct tNode* Address;
typedef struct tNode {
    int id;
    ListDin parent;
    ListDin children;
} Node;

typedef struct {
    Address root;
} Tree;

/* Selektor */
#define Root(T) (T).root
#define Id(P) (P)->id
#define Parent(P) (P)->parent
#define Children(P) (P)->children

/* *** Konstruktor *** */
void CreateTree(Tree *T);
/* I.S. T sembarang */
/* F.S. Terbentuk pohon kosong */

void createNode(Address *P, int id, ListDin parent, ListDin children);
/* I.S. P sembarang */
/* F.S. Terbentuk node kosong */



#endif