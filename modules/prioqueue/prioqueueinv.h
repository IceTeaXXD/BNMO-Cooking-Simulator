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
boolean IsEmpty_Prioqueue (Prioqueueinv Q){
    return (Head(Q) == Nil) && (Tail(Q) == Nil);
}
/* Mengirim true jika Q kosong: lihat definisi di atas */

/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt_Prioqueue(Prioqueueinv Q){
    /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    
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

boolean IsFull_Prioqueue (Prioqueueinv Q){
    return (MaxElQ(Q) == NBElmt_Prioqueue(Q));
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty_Prioqueue (Prioqueueinv * Q, int Max){
    (*Q).T = (food *) malloc((Max) * sizeof(food));
    if ((*Q).T == NULL) {
        MaxElQ(*Q) = 0;
    }
    else {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
        MaxElQ(*Q) = Max;
    }
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi_Prioqueue(Prioqueueinv * Q){
    {
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    MaxElQ(*Q) = 0;
    free((*Q).T);
}
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue_Prioqueue (Prioqueueinv * Q, food X){
    boolean found;
    int idx;
    int i, j;
    food temp;
    TIME temp1,temp4;
    Word temp2,temp3;
    CreateTime(&temp1,0,0,0);
    CreateTime(&temp4,0,0,0);
    CreateFood(&temp,0,temp2,temp1,temp3,temp4);

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
        while (i != Head(*Q) && TIMEToMenit(FoodExpiry((Elmt(*Q, i)))) < TIMEToMenit(FoodExpiry((Elmt(*Q, j))))) {
            temp = Elmt(*Q, i);
            Elmt(*Q, i) = Elmt(*Q, j);
            Elmt(*Q, j) = temp;
            i = j;
            j = i == 0 ? MaxElQ(*Q) - 1 : i - 1;
        }
    }
}
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Dequeue_Prioqueue (Prioqueueinv * Q, food * X){
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
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioqueueinv (Prioqueueinv Q){
    food val;
    Prioqueueinv temp;
    temp = Q;
    int i = 1;
    if (!IsEmpty_Prioqueue(Q)) {
        while (!IsEmpty_Prioqueue(temp)) {
            Dequeue_Prioqueue(&temp, &val);
            //printf("%d %c\n", Time(val), Info(val));
            printf("%d. ",i);
            PrintWord(FoodName(val)); printf(" ");
            Timetokata(FoodExpiry(val)); printf("\n");
            i++;
        }
    }
    //printf("#\n");
}
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<time-1> <elemen-1>
...
<time-n> <elemen-n>
#
*/

#endif