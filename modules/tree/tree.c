#include <stdio.h>
#include "tree.h"


/* *** Konstruktor *** */
void CreateTree(Tree *T)
/* I.S. T sembarang */
/* F.S. Terbentuk pohon kosong */
{
    Root(*T) = Nil;
}

void createNode(Address *P, int id, ListDin parent, ListDin children)
/* I.S. P sembarang */
/* F.S. Terbentuk node kosong */
{
    *P = (Address) malloc(sizeof(Node));
    Id(*P) = id;
    Parent(*P) = parent;
    Children(*P) = children;
}

void AddChild(Tree *T, int id, int parent)
/* I.S. T terdefinisi, id dan parent terdefinisi */
{
    Address P;
    createNode(&P, id, Nil, Nil);
    if (Root(*T) == Nil) {
        Root(*T) = P;
    } else {
        Address Q = Root(*T);
        while (Id(Q) != parent) {
            Q = Next(Q);
        }
        InsertLast(&Children(Q), P);
    }
}

void PrintTree(Tree T)
/* I.S. T terdefinisi */
/* F.S. T dicetak secara preorder */
{
    if (Root(T) != Nil) {
        printf("%d ", Id(Root(T)));
        PrintTree(Children(Root(T)));
    }
}