#include "food.h"
#include "../utility/boolean.h"
#include "../prioqueue/prioqueueinv.h"
#include "../tree/tree.h"
//#include "../time/time.c"
//#include "../wordmachine/wordmachine.c"
//#include "../liststatik/liststatik.c"
//#include "../wordmachine/charmachine.c"

void CreateFood(food *x, int id, Word name, TIME expiry, Word action, TIME delivery){
    FoodId(*x) = id;
    FoodName(*x) = name;
    FoodExpiry(*x) = expiry;
    FoodAction(*x) = action;
    FoodTime(*x) = delivery;
}

void DisplayFood(food x){
    //printf("%d ",FoodId(x));
    PrintWord(FoodName(x));
    printf(" - ");
    Timetokata(FoodExpiry(x));
    printf(" - ");
    PrintWord(FoodAction(x));
    printf(" - ");
    Timetokata(FoodTime(x));
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
    //printf("[");
    for (i = 0; i < listLength_ListFoodStatik(l); i++) {
        printf("    %d. ", i + 1);
        PrintWord(FoodName(LISTELMT(l,i))); printf(" - ");
        printf("Kadaluwarsa : ");
        Timetokata(FoodExpiry(LISTELMT(l,i))); printf(" - ");
        PrintWord(FoodAction(LISTELMT(l,i))); printf(" - ");
        printf("Process Time : ");
        Timetokata(FoodTime(LISTELMT(l,i)));
        printf("\n");
        /*for (s = FoodName(LISTELMT(l, i))[0]; *s != '\0'; s++)
        {
            printf("%c", *s);
        }*/
        //if (i < listLength_ListFoodStatik(l) - 1)
            //printf(",");
    }
    //printf("]");
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
void deleteFirst_ListFoodStatik(ListFoodStatik *l, ElType *val){
    int i;
    food undef;
    FoodId(undef) = LISTMARK;
    if (!isEmpty_ListFoodStatik(*l)){
        *val = LISTELMT(*l, 0);
        for (i = 0; i < listLength_ListFoodStatik(*l) - 1; i++){
            LISTELMT(*l, i) = LISTELMT(*l, i + 1);
            }
        }
        LISTELMT(*l, listLength_ListFoodStatik(*l) - 1) = undef; 
}

void deleteAt_ListFoodStatik(ListFoodStatik *l, ElType *val, IdxType idx){
    int i;
    food undef;
    FoodId(undef) = LISTMARK;
    if (!isEmpty_ListFoodStatik(*l)){
        *val = LISTELMT(*l, idx);
        for (i = idx; i < listLength_ListFoodStatik(*l) - 1; i++){
            LISTELMT(*l, i) = LISTELMT(*l, i + 1);
            }
        }
        LISTELMT(*l, listLength_ListFoodStatik(*l) - 1) = undef;
}

void deleteLast_ListFoodStatik(ListFoodStatik *l, ElType *val){
    food undef;
    FoodId(undef) = LISTMARK;
    if (!isEmpty_ListFoodStatik(*l)){
        *val = LISTELMT(*l, listLength_ListFoodStatik(*l) - 1);
        LISTELMT(*l, listLength_ListFoodStatik(*l) - 1) = undef;
    }
}
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
            Timetokata(FoodTime(LISTELMT(Foods, i)));
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
                        Timetokata(FoodTime(LISTELMT(Foods, i)));
                        printf(".\n");
                        FoodTime(LISTELMT(Foods, i)).MM++;
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

food idtofood(int id, ListFoodStatik L){
    int i = 0;
    food temp;
    boolean flag = false;
    while(!flag){
        if (FoodId(LISTELMT(L,i)) == id){
            flag = true;
        }
        else {
            i++;
        }
    }
    return LISTELMT(L, i);
    
}


void CHOP(Prioqueueinv *Inventory, ListFoodStatik Foods, Tree T, Prioqueueinv *Process){
    printf("=======================================\n");
    printf("=                 CHOP                =\n");
    printf("=======================================\n");
    printf("Pilih bahan makanan yang ingin di-CHOP:\n");

    ListFoodStatik foodAvailable;
    ListStatik childrens;
    CreateListFoodStatik(&foodAvailable);

    int i, j, count;

    if(IsEmpty_Prioqueue(*Inventory)){
        printf("Inventory Kosong\n");
    }
    else{
        // check apakah ada parent di food di inventory yang bisa di chop
        count = 0;
        for (i=0;i<NBElmt_Prioqueue(*Inventory);i++){
            addressTree child = getAddress(T.root,FoodId(Elmt(*Inventory,i)));
            addressTree parent = getParent(T.root,child);
            if (parent != NULL){
                food parentFood = idtofood(parent->data, Foods);
                if (compareString(FoodAction(parentFood),"Chop")){ 
                    count++;
                    printf("    %d. ", count);
                    PrintWord(FoodName(parentFood));
                    printf(" (");
                    Timetokata(FoodTime(parentFood));
                    printf(")\n");
                    insertLast_ListFoodStatik(&foodAvailable, parentFood);
                }
            }
        }

        if (isEmpty_ListFoodStatik(foodAvailable)){
            printf("Tidak ada bahan makanan yang bisa di-CHOP.\n");
        }

        else{
            printf("\nKirim 0 untuk cancel CHOP.");
            printf("\n\nEnter Command: ");
            STARTWORD();
            
            if (WordIsInt(currentWord)){
                int idx = WordToInt(currentWord);
                if (idx == 0){
                    printf("Exiting Chop.\n");
                }

                else if  (idx > 0 && idx <= count){
                    int j = 0;
                    for (i=0;i<listLength_ListFoodStatik(foodAvailable);i++){
                        j++;
                        if (j == idx){
                            printf("Berhasil memotong ");
                            PrintWord(FoodName(LISTELMT(foodAvailable, i)));
                            printf(". ");
                            PrintWord(FoodName(LISTELMT(foodAvailable, i)));
                            printf(" akan diantar dalam ");
                            Timetokata(FoodTime(LISTELMT(foodAvailable, i)));
                            printf(".\n");
                            FoodTime(LISTELMT(foodAvailable, i)).MM++;
                            addressTree parent = getAddress(T.root, FoodId(LISTELMT(foodAvailable, i)));
                            childrens = getChild(parent);
                            food childFood = idtofood(LISTELMT(childrens, 0), Foods);
                            if (NBElmt_Prioqueue(*Inventory) == 1){
                                MakeEmpty_Prioqueue(Inventory,1000);
                            }
                            else {
                                for (j=0;j<NBElmt_Prioqueue(*Inventory);j++){
                                    if (FoodId(Elmt(*Inventory,j)) == FoodId(childFood)){
                                        Dequeue_idx_Prioqueue(Inventory, j);
                                        break;
                                    }
                                }
                            }
                            Enqueue_Prioqueue(Process, LISTELMT(foodAvailable, i));
                            break;
                        }
                    }
                }
                else {
                    printf("Invalid input.\n");
                }
            }
        }
    }
}

void BOIL(Prioqueueinv *Inventory, ListFoodStatik Foods, Tree T, Prioqueueinv *Process){
    printf("=======================================\n");
    printf("=                 BOIL                =\n");
    printf("=======================================\n");
    printf("Pilih bahan makanan yang ingin di-BOIL:\n");

    ListFoodStatik foodAvailable;
    ListStatik childrens;
    CreateListFoodStatik(&foodAvailable);

    int i, j, count;

    if(IsEmpty_Prioqueue(*Inventory)){
        printf("Inventory Kosong\n");
    }
    else{
        // check apakah ada parent di food di inventory yang bisa di chop
        count = 0;
        for (i=0;i<NBElmt_Prioqueue(*Inventory);i++){
            addressTree child = getAddress(T.root,FoodId(Elmt(*Inventory,i)));
            addressTree parent = getParent(T.root,child);
            if (parent != NULL){
                food parentFood = idtofood(parent->data, Foods);
                if (compareString(FoodAction(parentFood),"Boil")){ 
                    count++;
                    printf("    %d. ", count);
                    PrintWord(FoodName(parentFood));
                    printf(" (");
                    Timetokata(FoodTime(parentFood));
                    printf(")\n");
                    insertLast_ListFoodStatik(&foodAvailable, parentFood);
                }
            }
        }

        if (isEmpty_ListFoodStatik(foodAvailable)){
            printf("Tidak ada bahan makanan yang bisa di-BOIL.\n");
        }

        else{
            printf("\nKirim 0 untuk cancel BOIL.");
            printf("\n\nEnter Command: ");
            STARTWORD();
            
            if (WordIsInt(currentWord)){
                int idx = WordToInt(currentWord);
                if (idx == 0){
                    printf("Exiting Boil.\n");
                }

                else if  (idx > 0 && idx <= count){
                    int j = 0;
                    for (i=0;i<listLength_ListFoodStatik(foodAvailable);i++){
                        j++;
                        if (j == idx){
                            printf("Berhasil merebus ");
                            PrintWord(FoodName(LISTELMT(foodAvailable, i)));
                            printf(". ");
                            PrintWord(FoodName(LISTELMT(foodAvailable, i)));
                            printf(" akan diantar dalam ");
                            Timetokata(FoodTime(LISTELMT(foodAvailable, i)));
                            printf(".\n");
                            FoodTime(LISTELMT(foodAvailable, i)).MM++;
                            addressTree parent = getAddress(T.root, FoodId(LISTELMT(foodAvailable, i)));
                            childrens = getChild(parent);
                            food childFood = idtofood(LISTELMT(childrens, 0), Foods);
                            if (NBElmt_Prioqueue(*Inventory) == 1){
                                MakeEmpty_Prioqueue(Inventory,1000);
                            }
                            else {
                                for (j=0;j<NBElmt_Prioqueue(*Inventory);j++){
                                    if (FoodId(Elmt(*Inventory,j)) == FoodId(childFood)){
                                        Dequeue_idx_Prioqueue(Inventory, j);
                                        break;
                                    }
                                }
                            }
                            Enqueue_Prioqueue(Process, LISTELMT(foodAvailable, i));
                            break;
                        }
                    }
                }
                else {
                    printf("Invalid input.\n");
                }
            }
        }
    }
}

void MIX(Prioqueueinv *Inventory, ListFoodStatik Foods, Tree T, Prioqueueinv *Process){
    printf("=======================================\n");
    printf("=                  MIX                 =\n");
    printf("=======================================\n");
    printf("Pilih bahan makanan yang ingin di-MIX:\n");

    ListFoodStatik foodAvailable;
    ListStatik childrens;
    CreateListFoodStatik(&foodAvailable);
    addressTree temp = T.root;
    food tempf;
    int i, j, count, counts,k, i1;
    boolean flag = false;
    addressTree temp1,temp2;
    count = 0;
    if(IsEmpty_Prioqueue(*Inventory)){
        printf("Inventory Kosong\n");
    }
    else {
        // check apakah ada parent di food di inventory yang bisa di Mix
        if (NBElmt_Prioqueue(*Inventory) >= 2){
            for (j = 0; j < NBElmt_Prioqueue(*Inventory); j++){
                temp1 = getAddress(temp, FoodId(Elmt(*Inventory,j)));
                temp2 = getParent(temp, temp1);
                if (temp2 != NULL){
                    tempf = idtofood(temp2->data, Foods);
                    if (compareString(FoodAction(tempf),"Mix") && indexOf_ListFoodStatik(foodAvailable, FoodId(tempf)) == IDX_UNDEF){
                        count++;
                        printf("    %d. ", count);
                        PrintWord(FoodName(tempf));
                        printf(" (");
                        Timetokata(FoodTime(tempf));
                        printf(")\n");
                        insertLast_ListFoodStatik(&foodAvailable, tempf);
                    }
                }

            }

        }
        if (isEmpty_ListFoodStatik(foodAvailable)){
            printf("Tidak ada bahan makanan yang bisa di-Mix.\n");
        } else {
            printf("\nKirim 0 untuk cancel MIX.");
            printf("\n\nEnter Command: ");
            STARTWORD();
            
            if (WordIsInt(currentWord)){
                int idx = WordToInt(currentWord);
                if (idx == 0){
                    printf("Exiting Mix.\n");
                }

                else if  (idx > 0 && idx <= count){
                    int j = 0;
                    for (i=0;i<listLength_ListFoodStatik(foodAvailable);i++){
                        j++;
                        if (j == idx){
                            tempf = LISTELMT(foodAvailable, i);
                            childrens = getChild(getAddress(temp, FoodId(tempf)));
                            for (i1 = 0; i1 < listLength_ListStatik(childrens); i1++){
                                for (k = 0; k < NBElmt_Prioqueue(*Inventory); k++){
                                    if (LISTELMT(childrens, i1) == FoodId(Elmt(*Inventory,k))){
                                        flag = true;
                                        break;
                                    }
                                    
                                }
                                if (!flag) {
                                    break;
                                    }
                                if (i1 != listLength_ListStatik(childrens) - 1){
                                        flag = false;
                                    } 
                            }
                            if (flag){
                                printf("Berhasil Melakukan Mix! Makanan ");
                                PrintWord(FoodName(tempf));
                                printf(" Tercipta!. ");
                                PrintWord(FoodName(tempf));
                                printf(" akan diantar dalam ");
                                Timetokata(FoodTime(tempf));
                                printf(".\n");
                                FoodTime(LISTELMT(foodAvailable, i)).MM++;
                                for (i1 = 0; i1 < listLength_ListStatik(childrens); i1++){
                                    for (k = 0; k < NBElmt_Prioqueue(*Inventory); k++){
                                        if (LISTELMT(childrens, i1) == FoodId(Elmt(*Inventory,k))){
                                            if (NBElmt_Prioqueue(*Inventory) == 1){
                                                MakeEmpty_Prioqueue(Inventory,1000);
                                                break;
                                            } else {
                                                Dequeue_idx_Prioqueue(Inventory, k);
                                                break;
                                            }
                                        }
                                    }
                                }
                                Enqueue_Prioqueue(Process, LISTELMT(foodAvailable, i));
                                break;

                            } else {
                                printf("Bahan Kamu kurang cok\n");
                            }
                        }
                }
            }
            else {
                    printf("Invalid input.\n");
                }
        }
    }
}
}

void FRY(Prioqueueinv *Inventory, ListFoodStatik Foods, Tree T, Prioqueueinv *Process){
    printf("=======================================\n");
    printf("=                  FRY                 =\n");
    printf("=======================================\n");
    printf("Pilih bahan makanan yang ingin di-FRY:\n");

    ListFoodStatik foodAvailable;
    ListStatik childrens;
    CreateListFoodStatik(&foodAvailable);
    addressTree temp = T.root;
    food tempf;
    int i, j, count, counts,k, i1;
    boolean flag = false;
    addressTree temp1,temp2;
    count = 0;
    if(IsEmpty_Prioqueue(*Inventory)){
        printf("Inventory Kosong\n");
    }
    else {
        // check apakah ada parent di food di inventory yang bisa di Mix
        if (NBElmt_Prioqueue(*Inventory) >= 2){
            for (j = 0; j < NBElmt_Prioqueue(*Inventory); j++){
                temp1 = getAddress(temp, FoodId(Elmt(*Inventory,j)));
                temp2 = getParent(temp, temp1);
                if (temp2 != NULL){
                    tempf = idtofood(temp2->data, Foods);
                    if (compareString(FoodAction(tempf),"Fry") && indexOf_ListFoodStatik(foodAvailable, FoodId(tempf)) == IDX_UNDEF){
                        count++;
                        printf("    %d. ", count);
                        PrintWord(FoodName(tempf));
                        printf(" (");
                        Timetokata(FoodTime(tempf));
                        printf(")\n");
                        insertLast_ListFoodStatik(&foodAvailable, tempf);
                    }
                }

            }

        }
        if (isEmpty_ListFoodStatik(foodAvailable)){
            printf("Tidak ada bahan makanan yang bisa di-Fry.\n");
        } else {
            printf("\nKirim 0 untuk cancel FRY.");
            printf("\n\nEnter Command: ");
            STARTWORD();
            
            if (WordIsInt(currentWord)){
                int idx = WordToInt(currentWord);
                if (idx == 0){
                    printf("Exiting Fry.\n");
                }

                else if  (idx > 0 && idx <= count){
                    int j = 0;
                    for (i=0;i<listLength_ListFoodStatik(foodAvailable);i++){
                        j++;
                        if (j == idx){
                            tempf = LISTELMT(foodAvailable, i);
                            childrens = getChild(getAddress(temp, FoodId(tempf)));
                            for (i1 = 0; i1 < listLength_ListStatik(childrens); i1++){
                                for (k = 0; k < NBElmt_Prioqueue(*Inventory); k++){
                                    if (LISTELMT(childrens, i1) == FoodId(Elmt(*Inventory,k))){
                                        flag = true;
                                        break;
                                    }
                                    
                                }
                                if (!flag) {
                                    break;
                                    }
                                if (i1 != listLength_ListStatik(childrens) - 1){
                                        flag = false;
                                    } 
                            }
                            if (flag){
                                printf("Berhasil Melakukan Fry! Makanan ");
                                PrintWord(FoodName(tempf));
                                printf(" Tercipta!. ");
                                PrintWord(FoodName(tempf));
                                printf(" akan diantar dalam ");
                                Timetokata(FoodTime(tempf));
                                printf(".\n");
                                FoodTime(LISTELMT(foodAvailable, i)).MM++;
                                for (i1 = 0; i1 < listLength_ListStatik(childrens); i1++){
                                    for (k = 0; k < NBElmt_Prioqueue(*Inventory); k++){
                                        if (LISTELMT(childrens, i1) == FoodId(Elmt(*Inventory,k))){
                                            if (NBElmt_Prioqueue(*Inventory) == 1){
                                                MakeEmpty_Prioqueue(Inventory,1000);
                                                break;
                                            } else {
                                                Dequeue_idx_Prioqueue(Inventory, k);
                                                break;
                                            }
                                        }
                                    }
                                }
                                Enqueue_Prioqueue(Process, LISTELMT(foodAvailable, i));
                                break;

                            } else {
                                printf("Bahan Kamu kurang cok\n");
                            }
                        }
                    }
                }
            }
        }
    }
}