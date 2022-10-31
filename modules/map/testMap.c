#include "map.c"

int main(){
    POINT S;
    Matrix m;
    ReadMap_FILE(&m, &S, "testMap.txt");
    displayMap(m);
    TulisPOINT(S);
    char move;

    while(true){
        scanf("%c", move);
        if(move=='w'){
            moveNorth(&m, &S);
        }
        else if(move=='a'){
            moveWest(&m, &S);
        }
        else if(move=='s'){
            moveSouth(&m, &S);
        }
        else if(move=='d'){
            moveEast(&m, &S);
        }
        displayMap(m);
        TulisPOINT(S);



    }


    return 0;
}