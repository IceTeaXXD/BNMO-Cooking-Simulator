#include "map.c"

int main(){
    POINT S;
    Matrix m;
    ReadMap_FILE(&m, &S, "testMap.txt");
    displayMap(m);
    TulisPOINT(S);
    char move;
    boolean flag = true;

    while (flag){
        scanf("%c", &move);
        if (move == 'w'){
            moveNorth(&m, &S);
            displayMap(m);
            TulisPOINT(S);
        }
        else if (move == 's'){
            moveSouth(&m, &S);
            displayMap(m);
            TulisPOINT(S);
        }
        else if (move == 'a'){
            moveWest(&m, &S);
            displayMap(m);
            TulisPOINT(S);
        }
        else if (move == 'd'){
            moveEast(&m, &S);
            displayMap(m);
            TulisPOINT(S);
        }
        else if (move == 'q'){
            flag = false;
        }
    }
    return 0;
}