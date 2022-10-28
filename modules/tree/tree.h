/* ADT N-ARY TREE */

#ifndef TREE_H
#define TREE_H

#include "../utility/boolean.h"
#include "../matrix/matrix.h"
#include "../liststatik/liststatik.h"
#include "../wordmachine/charmachine.h"
#include "../wordmachine/wordmachine.h"


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

#endif