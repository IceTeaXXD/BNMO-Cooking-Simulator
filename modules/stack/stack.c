#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void CreateStack(Stack *s)
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack s yang kosong */
{
    s->TOP = NULL;
}

void push(Stack *s, Stack_infotype x)
/* Menambahkan x sebagai elemen Stack s */
/* I.S. s mungkin kosong, x terdefinisi */
/* F.S. x menjadi Top yang baru jika alokasi x berhasil, */
/*      jika tidak, s tetap */
/* Pada dasarnya adalah operasi insertFirst pada list linier */
{
    Address p = (Address) malloc(sizeof(Node_stack));
    if (p != NULL)
    {
        INFO(p) = x;
        NEXT(p) = s->TOP;
        s->TOP = p;
    }

}
void pop(Stack *s, Stack_infotype *x)
/* Menghapus Top dari Stack s */
/* I.S. s tidak kosong */
/* F.S. x adalah nilai elemen Top yang lama, */
/*      elemen Top yang lama didealokasi */
/* Pada dasarnya adalah operasi deleteFirst pada list linier */
{
    if(!isStackEmpty(*s))
    {
        Address p = s->TOP;
        *x = INFO(p);
        s->TOP = NEXT(p);
        free(p);
    }
    else{
        printf("Stack is empty\n");
    }

}

boolean isStackEmpty(Stack s){
    return (s.TOP == NULL);
}