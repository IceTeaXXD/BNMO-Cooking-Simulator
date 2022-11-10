#include "listdin.c"
#include <stdio.h>

int main(){
    ListDin L;
    CreateListDin(&L, 25);
    readList_ListDin(&L);
    printList_ListDin(L);
    printf("Panjang List: %d\n", listLength_ListDin(L));
    dealocateList_ListDin(&L);
    printList_ListDin(L);
    printf("Panjang List: %d\n", listLength_ListDin(L));
}   