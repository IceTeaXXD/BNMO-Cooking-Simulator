#include "listfood.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListFoodStatik(ListFoodStatik *l){
    int i;
    food undef;
    FoodId(undef) = LISTMARK;
    for (i = 0; i < CAPACITY; i++){
        LISTELMT(*l, i) = undef;
    }
}
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan id food = LISTMARK */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength_ListFoodStatik(ListFoodStatik l){
    int i, count;
    count = 0;
    for (i = 0 ; i < CAPACITY ; i++){
        if (FoodId(LISTELMT(l, i)) != LISTMARK){
            count++;
        }
    }
    return count;
}
/* Mengirimkan banyaknya elemen efektif List food */
/* Mengirimkan nol jika List kosong */  

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty_ListFoodStatik(ListFoodStatik l){
    return (listLength_ListFoodStatik(l) == 0);
}
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */

void printList_ListFoodStatik(ListFoodStatik l){
    int i;
    printf("[");
    for (i = 0; i < listLength_ListFoodStatik(l); i++) {
        printf("%s", FoodName(LISTELMT(l, i)));
        if (i < listLength_ListFoodStatik(l) - 1)
            printf(",");
    }
    printf("]");
}
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */


/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf_ListFoodStatik(ListFoodStatik l, int val){
    int i = 0;
    boolean found = false;
    while (!found && i < listLength_ListFoodStatik(l)) {
        if (FoodId(LISTELMT(l, i)) == val) {
            found = true;
        } else {
            i++;
        }
    }
    if (found) {
        return i;
    } else {
        return IDX_UNDEF;
    }

}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst_ListStatik(ListFoodStatik *l, ElType val){

    int i;
    for (i = listLength_ListFoodStatik(*l); i > 0; i--) {
        LISTELMT(*l, i) = LISTELMT(*l, i - 1);
    }
    LISTELMT(*l, 0) = val;

}
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
void insertAt_ListStatik(ListFoodStatik *l, ElType val, IdxType idx){
    int i;
    for (i = listLength_ListFoodStatik(*l); i > idx; i--) {
        LISTELMT(*l, i) = LISTELMT(*l, i - 1);
    }
    LISTELMT(*l, idx) = val;
}
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
void insertLast_ListStatik(ListFoodStatik *l, ElType val){
    LISTELMT(*l, listLength_ListFoodStatik(*l)) = val;
}
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
