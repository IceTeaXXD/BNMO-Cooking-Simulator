/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef STACK_H
#define STACK_H

#include "../utility/boolean.h"
#include "../simulator/simulator.h"
#include "../prioqueue/prioqueueinv.h"
#include "../matrix/matrix.h"
#include "../time/time.h"

#define Nil -1
#define stack_MaxEl 100
/* Nil adalah stack dengan elemen kosong . */

typedef struct node_stack* Address;

typedef struct{
  player P;
  TIME GameTime;
  Matrix Map;
  Prioqueueinv Delivery;
  Prioqueueinv Process;
  Address next;
} Stack_infotype;

typedef struct node_stack{
  Stack_infotype info;
  Address next;
} Node_stack;

typedef struct{
  Address TOP;
} Stack;

/* Selektor */
#define     NEXT(p) (p)->next
#define     INFO(p) (p)->info
#define ADDR_TOP(s) (s).addrTop
#define      TOP(s) (s).addrTop->info 

void CreateStack(Stack *s);
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack s yang kosong */

void push(Stack *s, Stack_infotype x);
/* Menambahkan x sebagai elemen Stack s */
/* I.S. s mungkin kosong, x terdefinisi */
/* F.S. x menjadi Top yang baru jika alokasi x berhasil, */
/*      jika tidak, s tetap */
/* Pada dasarnya adalah operasi insertFirst pada list linier */

void pop(Stack *s, Stack_infotype *x);
/* Menghapus Top dari Stack s */
/* I.S. s tidak kosong */
/* F.S. x adalah nilai elemen Top yang lama, */
/*      elemen Top yang lama didealokasi */
/* Pada dasarnya adalah operasi deleteFirst pada list linier */
boolean isStackEmpty(Stack s);
#endif