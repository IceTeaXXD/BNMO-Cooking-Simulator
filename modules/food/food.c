#include "food.h"
#include "../utility/boolean.h"
//#include "../prioqueue/prioqueueinv.h"
//#include "../time/time.c"
//#include "../wordmachine/wordmachine.c"
//#include "../wordmachine/charmachine.c"

void CreateFood(food *x, int id, Word name, TIME expiry, Word action, TIME delivery){
    FoodId(*x) = id;
    FoodName(*x) = name;
    FoodExpiry(*x) = expiry;
    FoodAction(*x) = action;
    FoodDelivery(*x) = delivery;
}

void DisplayFood(food x){
    //printf("%d ",FoodId(x));
    PrintWord(FoodName(x));
    printf(" - ");
    Timetokata(FoodExpiry(x));
    printf(" - ");
    PrintWord(FoodAction(x));
    printf(" - ");
    Timetokata(FoodDelivery(x));
}

/*-------------------------------------*/
/*-------------List Food---------------*/

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
    char *s;
    printf("[");
    for (i = 0; i < listLength_ListFoodStatik(l); i++) {
        PrintWord(FoodName(LISTELMT(l,i)));
        /*for (s = FoodName(LISTELMT(l, i))[0]; *s != '\0'; s++)
        {
            printf("%c", *s);
        }*/
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
void insertFirst_ListFoodStatik(ListFoodStatik *l, ElType val){

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
void insertAt_ListFoodStatik(ListFoodStatik *l, ElType val, IdxType idx){
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
void insertLast_ListFoodStatik(ListFoodStatik *l, ElType val){
    LISTELMT(*l, listLength_ListFoodStatik(*l)) = val;
}
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

void ReadFood_FILE(char filename[], ListFoodStatik *listfood){
    int N;
    STARTWORD_FILE(filename);
    //acquiring N
    N = WordToInt(currentWord);
    ADVWORD();
    int i;
    // if (N == 0) {
    //     printf("N=0\n");
    // } else {
    //     printf("N=%d\n",N);
    // }
    for (i = 0; i<N; i++){
        Word name, action;
        int j=0, k, id=0, p;
        int DDexp=0, HHexp=0, MMexp=0;
        int DDdlv=0, HHdlv=0, MMdlv=0;
        Word NameTemp;
        TIME expiry, delivery;
        food x;
        id = WordToInt(currentWord); //Food ID
        ADVWORD();
        NameTemp = currentWord;
        ADVWORD();
        while (!WordIsInt(currentWord)){
            NameTemp = MergeWord(NameTemp, currentWord);
            ADVWORD();
        }
        name = NameTemp;
        // for (p=0;p<NameTemp.Length;p++){
        //     name[j]=NameTemp.TabWord[p];
        //     j++;
        // }
        // name[j]='\0';
        DDexp = WordToInt(currentWord);
        ADVWORD();
        HHexp = WordToInt(currentWord);
        ADVWORD();
        MMexp = WordToInt(currentWord);
        CreateTime(&expiry, DDexp, HHexp, MMexp);   //Food expiry
        ADVWORD();
        DDdlv = WordToInt(currentWord);
        ADVWORD();
        HHdlv = WordToInt(currentWord);
        ADVWORD();
        MMdlv = WordToInt(currentWord);
        CreateTime(&delivery, DDdlv, HHdlv, MMdlv); //Food delivery
        ADVWORD();
        action = currentWord;
        // for (k = 0; k < currentWord.Length; k++) {
        //     action[k] = currentWord.TabWord[k];       //Food action
        // }
        // action[k] = '\0';
        ADVWORD();
        CreateFood(&x, id, name, expiry, action, delivery);
        insertLast_ListFoodStatik(listfood, x);
        //DisplayFood(x);
        //printf("\n");
    }
}

void BUY(ListFoodStatik Foods, Prioqueueinv *Delivery){
    printf("======================\n");
    printf("=        BUY         =\n");
    printf("======================\n");
    printf("List Bahan Makanan:\n");
    int i,count;
    // hitung berapa food yang aksinya Buy
    count = 0;
    for (i=0;i<listLength_ListFoodStatik(Foods);i++){
        if (compareString(FoodAction(LISTELMT(Foods,i)),"Buy")){
            count++;
            printf("    %d. ", count);
            PrintWord(FoodName(LISTELMT(Foods, i)));
            printf(" (");
            Timetokata(FoodDelivery(LISTELMT(Foods, i)));
            printf(")\n");
        }
    }

    printf("\nKirim 0 untuk exit.\n");
    printf("\nEnter Command: ");
    STARTWORD();
    if (WordIsInt(currentWord)){
        int idx = WordToInt(currentWord);
        if (idx == 0){
            printf("Exit BUY.\n");
        } else if (idx > 0 && idx <= count){
            int j = 0;
            for (i=0;i<listLength_ListFoodStatik(Foods);i++){
                if (compareString(FoodAction(LISTELMT(Foods,i)),"Buy")){
                    j++;
                    if (j == idx){
                        printf("Berhasil memesan ");
                        PrintWord(FoodName(LISTELMT(Foods, i)));
                        printf(". ");
                        PrintWord(FoodName(LISTELMT(Foods, i)));
                        printf(" akan diantar dalam ");
                        Timetokata(FoodDelivery(LISTELMT(Foods, i)));
                        printf(".\n");
                        FoodDelivery(LISTELMT(Foods, i)).MM++;
                        Enqueue_Prioqueue_Delivery(Delivery, LISTELMT(Foods, i));
                        break;
                    }
                }
            }
        } 
        else {
            printf("Invalid input.\n");
        }
    } 
    else {
        printf("Invalid input.\n");
    }
}