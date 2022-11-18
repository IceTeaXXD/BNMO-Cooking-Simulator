#include <stdio.h>
#include "set.h"

/* Definisi Set S kosong : S.Count = Nil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty_Set(Set *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */
{
    (*S).Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty_Set(Set S)
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */
{
    return (S.Count == Nil);
}

boolean IsFull_Set(Set S)
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */
{
    return (S.Count == MaxEl);
}

/* ********** Operator Dasar Set ********* */
void Insert_Set(Set *S, infotype_set Elmt)
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
    (*S).Elements[(*S).Count] = Elmt;
    (*S).Count++;
}

boolean IsMember_Set(Set S, infotype_set Elmt)
/* Mengembalikan true jika Elmt adalah member dari S */
{
    boolean found = false;
    int i = 0;
    while (i<S.Count && !found){
        if (S.Elements[i] == Elmt){
            found = true;
        } else {
            i++;
        }
    }

    return found; 

}

Set SetUnion(Set s1, Set s2)
// I.S. Isi set hanyalah angka 0 dan 1
// F.S. Dihasilkan S3 yaitu gabungan s1 dan s2, jika pada indeks yang sama s1 dan s2 memiliki angka yang beda, maka yang dimasukkan adalah angka 1
{
    Set S3;
    CreateEmpty_Set(&S3);
    int i = 0;
    while (i < s1.Count){
        if (s1.Elements[i] == s2.Elements[i]){
            Insert_Set(&S3, s1.Elements[i]);
        } else {
            Insert_Set(&S3, 1);
        }
        i++;
    }
    return S3;
}

boolean isSubset(Set s1, Set s2)
// Mengembalikan true jika s2 merupakan subset dari s1
{
    boolean subset = true;
    int i = 0;
    while (i<s2.Count && subset){
        if (!(IsMember_Set(s1, s2.Elements[i]))){
            subset = false;
        } else {
            i++;
        }
    }
    return subset;
}

void CreateEmpty_ListSet(ListSet *LS)
/* I.S. LS sembarang */
/* F.S. Terbentuk ListSet kosong */
{
    (*LS).ListCount = Nil;
}

void insert_ListSet(ListSet *LS, Set S)
/* I.S. LS mungkin kosong */
{
    (*LS).contents[(*LS).ListCount] = S;
    (*LS).ListCount++;
}

int main(){
    Set s1;
    CreateEmpty_Set(&s1);
    Insert_Set(&s1, 0);
    Insert_Set(&s1, 1);
    Insert_Set(&s1, 1);
    Insert_Set(&s1, 0);
    Set s2;
    CreateEmpty_Set(&s2);
    Insert_Set(&s2, 0);
    Insert_Set(&s2, 0);
    Insert_Set(&s2, 1);
    Insert_Set(&s2, 1);
    Set s3;
    s3 = SetUnion(s1, s2);
    // output s3
    int i;
    for (i=0; i<s3.Count; i++){
        printf("%d ", s3.Elements[i]);
    }
    if (isSubset(s1,s2)){
        printf("s2 subset s1");
    }
    // printf("%d\n", s3.Count);
    // printf("\n\n");
    // ListSet LS1;
    // CreateEmpty_ListSet(&LS1);
    // insert_ListSet(&LS1, s1);
    // insert_ListSet(&LS1, s2);
    // insert_ListSet(&LS1, s3);
    // printf("%d", LS1.contents[2].Count);
    // return 0;
}