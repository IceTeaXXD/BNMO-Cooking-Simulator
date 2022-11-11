#include <stdio.h>
#include "time.h"
#include "time.c"

int main(){
    TIME T, T1, T2;
    int Menit;

    // Create Time
    CreateTime(&T, 1, 2, 3);

    //Tulis Time
    printf("Cetak Time\n");
    TulisTIME(T);
    printf("\n");
    TulisTIME2(T);

    //Convert Time to Menit
    printf("\nConvert time ke menit: %ld\n", TIMEToMenit(T));

    //Convert Menit to Time
    printf("Masukkan menit: ");
    scanf("%d", &Menit);
    printf("Convert menit ke time: %d.%02d", MenitToTIME(Menit));

    // Tambah time
    printf("\nNext menit: ");
    TulisTIME(NextMenit(T));
    printf("\n");

    printf("Masukkan menit untuk ditambah: ");
    scanf("%d", &Menit);
    printf("Next n menit: ");
    TulisTIME(NextNMenit(T, Menit));
    printf("\n");

    // Kurang time
    printf("Prev menit: ");
    TulisTIME(PrevMenit(T));
    printf("\n");

    printf("Masukkan menit untuk dikurangi: ");
    scanf("%d", &Menit);
    printf("Prev n menit: ");
    TulisTIME(PrevNMenit(T, Menit));
    printf("\n");
    
    
    // Compare time
    printf("Apakah T1 dan T2 sama?\n");
    CreateTime(&T1, 2, 20, 30);
    CreateTime(&T2, 2, 20, 50);
    if (TEQ(T1, T2)){
        printf("Sama\n");
    }
    else if(TNEQ(T1, T2)){
        printf("Tidak sama\n");
    }
        if(TLT(T1, T2)){
            printf("T1 lebih kecil dari T2\n");
        }
        else if(TGT(T1, T2)){
            printf("T1 lebih besar dari T2\n");
        }
    
    printf("Durasi T1 dan T2: %d\n", Durasi(T1, T2));
    printf("Durasi T2 dan T1: %d\n", Durasi(T2, T1));

    return 0;
  
}