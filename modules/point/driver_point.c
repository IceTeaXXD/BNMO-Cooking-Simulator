#include <stdio.h>
#include "point.c"

int main(){
  POINT p1, p2;
  printf("Masukan x1 dan y1: ");
  BacaPOINT(&p1);
  printf("Masukan x2 dan y2: ");
  BacaPOINT(&p2);
  printf("\nDalam Koordinat bentuknya:");
  printf("\n Titik 1: ");
  TulisPOINT(p1);
  printf(" Titik 2: ");
  TulisPOINT(p2);
  printf("\n");

  if(EQ(p1, p2)){
    printf("P1 = P2\n");
  }else{
    printf("P1 != P2\n");
  }

  if(IsOrigin(p1)){
    printf("Titik pertama ada di (0,0)\n");
  }else if(IsOnSbX(p1)){
    printf("Titik pertama ada di sumbu x\n");
  }else if(IsOnSbY(p1)){
    printf("Titik pertama ada di sumbu y\n");    
  }
}