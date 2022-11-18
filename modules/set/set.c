#include <stdio.h>
#include "set.h"

/* Definisi Set S kosong : S.Count = Nil_SET */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty_Set(Set *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil_SET */
{
    (*S).Count = Nil_SET;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty_Set(Set S)
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil_SET */
{
    return (S.Count == Nil_SET);
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
    if (!(IsMember_Set(*S, Elmt))){
        (*S).Elements[(*S).Count] = Elmt;
        (*S).Count++;
    }
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
    Set s;
    CreateEmpty_Set(&s);
    int i;
    for(i=0; i<s1.Count; i++){
        Insert_Set(&s, s1.Elements[i]);
    }

    for (i=0; i<s2.Count; i++){
        Insert_Set(&s, s2.Elements[i]);
    }

    return s;
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
    (*LS).ListCount = Nil_SET;
}

void insert_ListSet(ListSet *LS, Set S)
/* I.S. LS mungkin kosong */
{
    (*LS).contents[(*LS).ListCount] = S;
    (*LS).ListCount++;
}

void delete_ListSet(ListSet *LS)
/*Hapus elemen terakhir dari LS, LS tidak mungkin kosong*/
{
    (*LS).ListCount--;
}

Set idtoset(Tree T, int id){
    Set S;
    CreateEmpty_Set(&S);
    addressTree p = getAddress(T.root, id);
    ListStatik l = getChild(p);
    int i ;
    for (i = 0 ; i < listLength_ListStatik(l) ; i++){
        Insert_Set(&S, LISTELMT(l, i));
    }
    S.foodID = id;
    return S;
}

ListSet treeToListSet(Tree T, ListFoodStatik foods){
    Set S;
    ListSet LS;
    CreateEmpty_ListSet(&LS);
    int i;
    for (i = 0 ; i < listLength_ListFoodStatik(foods) ; i++){
        S = idtoset(T, LISTELMT(foods, i).id);
        insert_ListSet(&LS, S);
    }
    return LS;
}

Set prioQueueToSet(Prioqueueinv Q){
    Set S;
    CreateEmpty_Set(&S);
    int i;
    for (i = 0 ; i < NBElmt_Prioqueue(Q) ; i++){
        Insert_Set(&S, Q.T[i].id);
    }
    return S;
}

void Rekomendasi(ListSet LS, Set inv, ListFoodStatik foods, Tree T){
    printf("=======================================\n");
    printf("=           REKOMENDASI RESEP         =\n");
    printf("=======================================\n");
    printf("Menampilkan list makanan yang dapat dibuat berdasarkan isi inventori:\n");
    int i,j,k,count,temp;
    count = 0;

    // if the children of a parent is in inventory, then insert the parent in the set
    for (k = 0 ; k < 5 ; k ++){ // 5 loops to ensure everythings in the set
        for (i = 0 ; i < listLength_ListFoodStatik(foods) ; i++){
            addressTree parent = getAddress(T.root, LISTELMT(foods, i).id);
            ListStatik children = getChild(parent);
            // children to set
            Set childSet;
            CreateEmpty_Set(&childSet);
            for (j = 0 ; j < listLength_ListStatik(children) ; j++){
                Insert_Set(&childSet, LISTELMT(children, j));
            }
            // if the children of a parent is in inventory, then insert the parent in the set
            if (isSubset(inv, childSet) && LS.contents[i].Count != 0){
                Insert_Set(&inv, LISTELMT(foods, i).id);
            }
        }
    }

    // print the food recipes that can be made
    for (i = 0 ; i < LS.ListCount ; i++){
        if (isSubset(inv, LS.contents[i]) && LS.contents[i].Count != 0){
            count++;
            food temp = idtofood(LS.contents[i].foodID, foods);
            printf("%d. ", count);
            PrintWord(temp.food_name);
            printf("\n");
        }
    }
    if(count == 0){
        printf("Tidak ada rekomendasi makanan untuk anda\n");
    }
}
// int main(){
//     Set s1;
//     CreateEmpty_Set(&s1);
//     Insert_Set(&s1, 1);
//     Insert_Set(&s1, 0);
//     Insert_Set(&s1, 1);
//     Set s2;
//     CreateEmpty_Set(&s2);
//     Insert_Set(&s2, 1);
//     Insert_Set(&s2, 0);
//     Insert_Set(&s2, 1);
//     Set s3;
//     s3 = SetUnion(s1, s2);
//     // output s3
//     int i;
//     for (i=0; i<s3.Count; i++){
//         printf("%d ", s3.Elements[i]);
//     }
//     if (isSubset(s1,s2)){
//         printf("s2 subset s1");
//     }
//     printf("%d\n", s3.Count);
//     printf("\n\n");
//     ListSet LS1;
//     CreateEmpty_ListSet(&LS1);
//     insert_ListSet(&LS1, s1);
//     insert_ListSet(&LS1, s2);
//     insert_ListSet(&LS1, s3);
//     printf("%d", LS1.contents[2].Count);
//     return 0;
// }