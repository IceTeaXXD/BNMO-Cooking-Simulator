/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen time */

#include <stdio.h>
#include <stdlib.h>
#include "prioqueuefood.h"
#include "../food/food.c"
/* ********* AKSES (Selektor) ********* */
/* Jika e adalah food dan Q adalah PrioQueueFood, maka akses elemen : */
/*
#define Time(e)     (e).time
#define Info(e)     (e).info
#define Head(Q)     (Q).HEAD
#define Tail(Q)     (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxElQ(Q)    (Q).MaxElQ
#define Elmt(Q,i)   (Q).T[(i)]
*/

/* ********* Prototype ********* */
boolean IsEmpty_Prioqueue(PrioQueueFood Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return (Head(Q) == Nil) && (Tail(Q) == Nil);
}
boolean IsFull_Prioqueue(PrioQueueFood Q)
    /* Mengirim true jika tabel penampung elemen Q sudah penuh */
    /* yaitu mengandung elemen sebanyak MaxElQ */
{
    return MaxElQ(Q) == NBElmt_Prioqueue(Q);
}
int NBElmt_Prioqueue(PrioQueueFood Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{    
    if (IsEmpty_Prioqueue(Q)){
        return 0;
    }
    else {
        if ((Tail(Q) - Head(Q)) >= 0){
            return Tail(Q) - Head(Q) + 1;
        }
        else {
            return MaxElQ(Q) - (Head(Q) - (Tail(Q) + 1));
        }
    }
}

/* *** Kreator *** */
void MakeEmpty_Prioqueue(PrioQueueFood *Q, int Max)
    /* I.S. sembarang */
    /* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
    /* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
    /* atau : jika alokasi gagal, Q kosong dg MaxElQ=0 */
    /* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    (*Q).T = (food *)malloc((Max) * sizeof(food));
    if ((*Q).T == NULL) {
        MaxElQ(*Q) = 0;
    }
    else {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
        MaxElQ(*Q) = Max;
    }
}

/* *** Destruktor *** */
void DeAlokasi_Prioqueue(PrioQueueFood *Q)
    /* Proses: Mengembalikan memori Q */
    /* I.S. Q pernah dialokasi */
    /* F.S. Q menjadi tidak terdefinisi lagi, MaxElQ(Q) diset 0 */
{
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    MaxElQ(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Enqueue_Prioqueue(PrioQueueFood *Q, food X)
    /* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan time */
    /* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
    /* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
            TAIL "maju" dengan mekanisme circular buffer; */
{
    boolean found;
    int idx;
    int i, j;
    food temp;

    // ALGORITMA
    if (IsEmpty_Prioqueue(*Q)) {
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoTail(*Q) = X;
    }
    else {
        Tail(*Q) = Tail(*Q) == MaxElQ(*Q) - 1 ? 0 : Tail(*Q) + 1;
        InfoTail(*Q) = X;
        i = Tail(*Q);
        j = i == 0 ? MaxElQ(*Q) - 1 : i - 1;
        while (i != Head(*Q) && TIMEToMenit(FoodExpiry(Elmt(*Q, i))) < TIMEToMenit(FoodExpiry(Elmt(*Q, j)))) {
            temp = Elmt(*Q, i);
            Elmt(*Q, i) = Elmt(*Q, j);
            Elmt(*Q, j) = temp;
            i = j;
            j = i == 0 ? MaxElQ(*Q) - 1 : i - 1;
        }
    }
}
void Dequeue_Prioqueue(PrioQueueFood *Q, food *X)
    /* Proses: Menghapus X pada Q dengan aturan FIFO */
    /* I.S. Q tidak mungkin kosong */
    /* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
            Q mungkin kosong */
{
    if (NBElmt_Prioqueue(*Q) == 1) {
        *X = InfoHead(*Q);
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else {
        *X = InfoHead(*Q);
        Head(*Q) = (Head(*Q) == MaxElQ(*Q) - 1) ? 0 : Head(*Q) + 1;
    }
}

/* Operasi Tambahan */
void PrintPrioQueueFood(PrioQueueFood Q)
    /* Mencetak isi queue Q ke layar */
    /* I.S. Q terdefinisi, mungkin kosong */
    /* F.S. Q tercetak ke layar dengan format:
    <time-1> <elemen-1>
    ...
    <time-n> <elemen-n>
    #
    */
{
    food val;
    PrioQueueFood temp;
    temp = Q;
    if (!IsEmpty_Prioqueue(Q)) {
        printf("\nPrio Queue:\n");
        while (!IsEmpty_Prioqueue(temp)) {
            Dequeue_Prioqueue(&temp, &val);
            DisplayFood(val);
            printf("\n");
        }
    }
    printf("#\n");
}
