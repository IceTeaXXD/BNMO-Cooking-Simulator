/* ADT Food */
/*Memiliki data ID makanan, Nama makanan, Waktu kedaluwarsa, Lokasi aksi, dan Lama pengiriman.*/

#ifndef FOOD_H
#define FOOD_H

#include "../utility/boolean.h"
#include "../time/time.h"

typedef struct
{
    int id;
    char *food_name;
    TIME expiry_time;
    char *action;
    TIME delivery_time;

}food;

#define FoodId(F) (F).id
#define FoodName(F) (F).food_name
#define FoodExpiry(F) (F).expiry_time
#define FoodAction(F) (F).action
#define FoodDelivery(F) (F).delivery_time

void CreateFood(food *x, int id, char name[], TIME expiry, char action[], TIME delivery);

void DisplayFood(food x);

void ReadFood_FILE(char filename[]);

#endif  