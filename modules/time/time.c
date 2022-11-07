#include <stdio.h>
#include "time.h"

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

    // if (Day(waktu) > 0){
    //     printf("%d Hari ", Day(waktu));
    // }
    // if (Hour(waktu) > 0){
    //     printf("%d Jam ", Hour(waktu));
    // }
    // if (MM(waktu) > 0){
    //     printf("%d menit", MM(waktu));
    // }
    // if (Day(waktu) == 0 && Hour(waktu) == 0 && MM(waktu) == 0){
    //     printf("0");
    // }
   
void TambahTime (TIME * T, int DD, int HH, int MM)
// menambah time dengan DD hari, HH jam, MM menit
{
    int menit;
    menit = TIMEToMenit(*T);
    menit += (DD*1440 + HH*60 + MM);
    *T = MenitToTIME(menit);
}

void timeLogic(int DD, int HH, int MM, TIME *gameTime, Prioqueueinv *Delivery, Prioqueueinv *Inventory)
{
    TIME temp;
    int deliveryTime;
    food f;
    // add time to gameTime
    TambahTime(gameTime, DD, HH, MM);

    // reduce time in fooddelivery
    int i;
    int timeAdded = DD*1440 + HH*60 + MM;
    for (i = 0 ; i < Delivery->MaxElQ ; i++){
        temp = Delivery->T[i].delivery_time;
        deliveryTime = TIMEToMenit(temp);
        if (deliveryTime - timeAdded > 0){
            Delivery->T[i].delivery_time = PrevNMenit(temp, timeAdded);
        }
        else{
            Delivery->T[i].delivery_time = MenitToTIME(0);
            Dequeue_Prioqueue(Delivery, &f);
            Enqueue_Prioqueue(Inventory,f);
        }
    }

    // reduce time in inventory
    for (i = 0 ; i < Inventory->MaxElQ ; i++){
        Inventory->T[i].expiry_time = PrevNMenit(Inventory->T[i].expiry_time, MM);
    }
}