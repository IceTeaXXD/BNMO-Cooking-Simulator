/* ADT Food */
/*Memiliki data ID makanan, Nama makanan, Waktu kedaluwarsa, Lokasi aksi, dan Lama pengiriman.*/

#ifndef FOOD_H
#define FOOD_H

#include "../utility/boolean.h"
#include "../time/time.h"

typedef struct
{
    int id;
    char food_name;
    TIME expiry_time;
    char location;
    int delivery_time;

}food;

#define ID(F) (F).id
#define FOOD_NAME(F) (F).food_name
#define EXPIRY_TIME(F) (F).expiry_time
#define LOCATION(F) (F).location
#define DELIVERY_TIME(F) (F).delivery_time

#endif  