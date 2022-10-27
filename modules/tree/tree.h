/* ADT N-ARY TREE */

#ifndef TREE_H
#define TREE_H

#include "../utility/boolean.h"

#define Nil NULL

/* Definisi Type Data */
typedef struct tNode *address;
typedef struct tNode {
    int data;
    address firstChild;
    address nextSibling;
} Node;

typedef struct {
    address root;
} Tree;


#define Data(P) (P)->data
#define FirstChild(P) (P)->firstChild
#define NextSibling(P) (P)->nextSibling
#define Root(T) (T).root

/* Definisi Pohon : */
/* Pohon kosong : P = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), FirstChild(P), NextSibling(P) */
/* Elemen terakhir pohon : jika NextSibling(P) = Nil, maka P adalah elemen terakhir pohon */

#endif