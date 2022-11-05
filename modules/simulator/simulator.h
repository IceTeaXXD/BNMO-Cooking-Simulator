/* ADT SIMULATOR */
/*Memiliki data ID makanan, Nama makanan, Waktu kedaluwarsa, Lokasi aksi, dan Lama pengiriman.*/

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "../utility/boolean.h"
#include "../point/point.h"
#include "../liststatik/liststatik.h"


typedef struct
{
    char* username;
    POINT loc;
    ListStatik inventory;
}player;

#define USERNAME(P) (P).username
#define LOC(P) (P).loc
#define INVENTORY(P) (P).inventory

#endif  