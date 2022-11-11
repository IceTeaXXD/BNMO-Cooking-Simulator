#include <stdio.h>
#include "time.h"

food foodAffected;
boolean adaNotif;
ListFoodStatik notif;
ListStatik jenis2Notif;

boolean IsTIMEValid(int D, int H, int M)
{
    return ((D>=0) && (H>=0) && (H<=23) && (M>=0) && (M<=59));
}

void CreateTime (TIME * T, int DD, int HH, int MM)
{
    (*T).DD = DD;
    (*T).HH = HH;
    (*T).MM = MM;
}

void BacaTIME (TIME * T)
{
    int DD, HH, MM;
    while (!IsTIMEValid(DD,HH,MM))
    {
        printf("Waktu tidak valid\n");
    }
    CreateTime(T, DD, HH, MM);
}

void TulisTIME (TIME T)
{
    printf("%02d:%02d:%02d", T.DD, T.HH, T.MM);
}

void TulisTIME2 (TIME T)
{
    printf("%d.%02d", T.HH, T.MM);
}

long TIMEToMenit (TIME T)
{
    return (T.DD*1440 + T.HH*60 + T.MM);
}

TIME MenitToTIME (long N)
{
    TIME T;
    T.DD = N/1440;
    T.HH = (N%1440)/60;
    T.MM = (N%1440)%60;
    return T;
}

boolean TEQ(TIME T1, TIME T2)
{
    return ((T1.DD==T2.DD) && (T1.HH==T2.HH) && (T1.MM==T2.MM));
}

boolean TNEQ(TIME T1, TIME T2)
{
    return (!TEQ(T1,T2));
}

boolean TLT(TIME T1, TIME T2)
{
    return (TIMEToMenit(T1)<TIMEToMenit(T2));
}

boolean TGT(TIME T1, TIME T2)
{
    return (TIMEToMenit(T1)>TIMEToMenit(T2));
}

TIME NextMenit(TIME T)
{
    return MenitToTIME(TIMEToMenit(T)+1);
}

TIME NextNMenit (TIME T, int N)
{
    return MenitToTIME(TIMEToMenit(T)+N);
}

TIME PrevMenit(TIME T)
{   
    int menit;
    menit = TIMEToMenit(T);
    if (menit-1 < 0) {
        menit = 1440;
    }
    menit -= 1;
    return MenitToTIME(menit);
}

TIME PrevNMenit (TIME T, int N)
{   
    int menit;
    menit = TIMEToMenit(T);
    if (menit-N < 0){
        menit += 1440;
    }
    menit -= N;
    return MenitToTIME(menit);
}

long Durasi (TIME TAw, TIME TAkh)
{
    int SAw, SAkh, Diff;
    SAw = TIMEToMenit(TAw);
    SAkh = TIMEToMenit(TAkh);
    Diff  = SAkh - SAw;
    if (SAw > SAkh){
        return Diff + 1440;
    }
    else{
        return Diff;
    }
}

void Timetokata(TIME waktu)
{
    if (Day(waktu) > 0 && Hour(waktu) == 0 && MM(waktu) == 0)
    {
        printf("%d hari", waktu.DD);
    }
    else if (Day(waktu) > 0 && Hour(waktu) > 0 && MM(waktu) == 0)
    {
        printf("%d hari %d jam", waktu.DD, waktu.HH);
    }
    else if (Day(waktu) > 0 && Hour(waktu) > 0 && MM(waktu) > 0)
    {
        printf("%d hari %d jam %d menit", waktu.DD, waktu.HH, waktu.MM);
    }
    else if (Day(waktu) == 0 && Hour(waktu) > 0 && MM(waktu) == 0)
    {
        printf("%d jam", waktu.HH);
    }
    else if (Day(waktu) == 0 && Hour(waktu) > 0 && MM(waktu) > 0)
    {
        printf("%d jam %d menit", waktu.HH, waktu.MM);
    }
    else if (Day(waktu) == 0 && Hour(waktu) == 0 && MM(waktu) > 0)
    {
        printf("%d menit", waktu.MM);
    }
}


void TambahTime (TIME * T, int DD, int HH, int MM)
// menambah time dengan DD hari, HH jam, MM menit
{
    int menit;
    menit = TIMEToMenit(*T);
    menit += (DD*1440 + HH*60 + MM);
    *T = MenitToTIME(menit);
}

// LOOPING INI MASIH TOLOL KYK HAIDAR
void timeLogic(int DD, int HH, int MM, TIME *gameTime, Prioqueueinv *Delivery, Prioqueueinv *Inventory)
{
    int timeAdded = DD*1440 + HH*60 + MM;
    int i;
    int temptime;
    TambahTime(gameTime, DD, HH, MM);
    int n = NBElmt_Prioqueue(*Delivery);
    int n1 = NBElmt_Prioqueue(*Inventory);
    for (i = 0; i < n; i++)
    {
        int deliveryTime = TIMEToMenit(Delivery->T[i].action_time);
        if (deliveryTime - timeAdded <= 0)
        {
            adaNotif = true;
            Dequeue_Prioqueue(Delivery, &foodAffected);
            temptime = TIMEToMenit(FoodExpiry(foodAffected));
            temptime += (deliveryTime - timeAdded);
            if (temptime > 0) {
                Enqueue_Prioqueue(Inventory, foodAffected);
                Inventory->T[i].expiry_time = MenitToTIME(temptime);
                insertLast_ListFoodStatik(&notif, foodAffected);
                insertLast_ListStatik(&jenis2Notif, 2);                 //makanan yang sudah sampai mempunyai jenis notifikasi 2
            } else {
                insertLast_ListFoodStatik(&notif, foodAffected);
                insertLast_ListStatik(&jenis2Notif, 3);                 //makanan yang sampai tapi busuk mempunyai jenis notifikasi 3
            }
        }
        else if (deliveryTime - timeAdded > 0)
        {
            Delivery->T[i].action_time= MenitToTIME(deliveryTime - timeAdded);
        }
    }
    if (n1 != 0){
        for (i = 0; i < n1; i++){
            int inventoryTime = TIMEToMenit(Inventory->T[i].expiry_time);
            if (inventoryTime - timeAdded <= 0)
            {
                adaNotif = true;
                if (NBElmt_Prioqueue(*Inventory) == 1){
                    Dequeue_Prioqueue(Inventory, &foodAffected);
                    MakeEmpty_Prioqueue(Inventory, 1000);
                } else {
                    Dequeue_Prioqueue(Inventory, &foodAffected);
                    //DisplayFood(foodAffected);
                }
                insertLast_ListFoodStatik(&notif, foodAffected);   
                insertLast_ListStatik(&jenis2Notif, 1);                 //makanan yang sudah kadaluarsa memnpunyai jenis notifikasi 1
            }
            else if (inventoryTime - timeAdded > 0)
            {
                Inventory->T[i].expiry_time= MenitToTIME(inventoryTime - timeAdded);
            } 
        }
    }

}