/* File : Prioqueueinv.h */
/* Definisi ADT Priority Queue Time dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen time */

#ifndef Prioqueueinv_H
#define Prioqueueinv_H

#include "../utility/boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include "../food/food.h"

#define Nil -1
/* Konstanta untuk mendefinisikan addressPrioqueue tak terdefinisi */

/* Definisi elemen dan addressPrioqueue */

/*typedef struct {
    int time;  /* [1..100], waktu dengan nilai 1..100 (1 adalah waktu adalah terendah) 
    char info;  /* elemen karakter 
} food;
*/
typedef int addressPrioqueue;   /* indeks tabel */ 


/* Contoh deklarasi variabel bertype Prioqueueinv : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct {
    food * T;   /* tabel penyimpan elemen */
    addressPrioqueue HEAD;  /* alamat penghapusan */
    addressPrioqueue TAIL;  /* alamat penambahan */
    int MaxElQ;     /* Max elemen queue */
} Prioqueueinv;
/* Definisi Prioqueueinv kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah Prioqueueinv, maka akses elemen : */
//#define Time(e)     (e).time
//#define Info(e)     (e).info
#define Head(Q)     (Q).HEAD
#define Tail(Q)     (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxElQ(Q)    (Q).MaxElQ
#define Elmt(Q,i)   (Q).T[(i)]

/* ********* Prototype ********* */
boolean IsEmpty_Prioqueue (Prioqueueinv Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */

/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt_Prioqueue(Prioqueueinv Q);
boolean IsFull_Prioqueue (Prioqueueinv Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty_Prioqueue (Prioqueueinv * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi_Prioqueue(Prioqueueinv * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue_Prioqueue (Prioqueueinv * Q, food X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Dequeue_Prioqueue (Prioqueueinv * Q, food * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioqueueinv (Prioqueueinv Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<time-1> <elemen-1>
...
<time-n> <elemen-n>
#
*/
void PrintInvPrio(Prioqueueinv Q);

void Enqueue_Prioqueue_Delivery(Prioqueueinv *Q, food X);

void deleteAt_Prioqueue(Prioqueueinv *Q, int idx, food *f);

void PrintCookPrio(Prioqueueinv Q);

int indexOf_Prioqueue(Prioqueueinv Q, int val);

void Dequeue_idx_Prioqueue(Prioqueueinv *Q, int x);

#endif