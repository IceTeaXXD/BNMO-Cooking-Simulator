/* ADT SIMULATOR */
/*Memiliki data ID makanan, Nama makanan, Waktu kedaluwarsa, Lokasi aksi, dan Lama pengiriman.*/

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "../utility/boolean.h"
#include "../adt.h"


typedef struct
{
    char username[100];
    POINT location;
    ListStatik inventory;
}player;

#define USERNAME(P) (P).username
#define LOCATION(P) (P).location
#define INVENTORY(P) (P).inventory

#endif  