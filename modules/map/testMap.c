#include "map.c"
#include "../wordmachine/wordmachine.c"
#include "../point/point.c"
#include "../matrix/matrix.c"
#include "../simulator/simulator.c"
#include "../prioqueue/prioqueueinv.c"

int main(){
    Matrix kulkas;
    POINT cursor;
    food pud;
    int insert, xSize=2, ySize=3;
    int i, j, tempx, tempy;
    boolean bool=true;
    createKulkas(10, 20, &kulkas);
    printf("input: ");
    scanf("%d", &insert);
    accessKulkas(&kulkas, &cursor);
    displayKulkas(kulkas);
    TulisPOINT(cursor);
    boolean flag = true;
    while (flag){
        STARTWORD();
        if (compareString(currentWord,"w")){
            moveNorth(&kulkas, &cursor, &bool);
            displayKulkas(kulkas);
            TulisPOINT(cursor);
        }
        else if (compareString(currentWord,"s")){
            moveSouth(&kulkas, &cursor, &bool);
            displayKulkas(kulkas);
            TulisPOINT(cursor);
        }
        else if (compareString(currentWord,"a")){
            moveWest(&kulkas, &cursor, &bool);
            displayKulkas(kulkas);
            TulisPOINT(cursor);
        }
        else if (compareString(currentWord,"d")){
            moveEast(&kulkas, &cursor, &bool);
            displayKulkas(kulkas);
            TulisPOINT(cursor);
        } else if (compareString(currentWord,"p")){
            insertResidentEvilInv(&kulkas,pud,&cursor);
        }
        else if (compareString(currentWord,"q")){
            flag = false;
        }
    }

    // POINT S;
    // Matrix m;
    // boolean bool = true;
    // ReadMap_FILE(&m, &S, "testMap.txt");
    // displayMap(m);
    // TulisPOINT(S);
    // char move;
    // boolean flag = true;

    // while (flag){
    //     scanf("%c", &move);
    //     if (move == 'w'){
    //         moveNorth(&m, &S, &bool);
    //         displayMap(m);
    //         TulisPOINT(S);
    //     }
    //     else if (move == 's'){
    //         moveSouth(&m, &S, &bool);
    //         displayMap(m);
    //         TulisPOINT(S);
    //     }
    //     else if (move == 'a'){
    //         moveWest(&m, &S, &bool);
    //         displayMap(m);
    //         TulisPOINT(S);
    //     }
    //     else if (move == 'd'){
    //         moveEast(&m, &S, &bool);
    //         displayMap(m);
    //         TulisPOINT(S);
    //     }
    //     else if (move == 'q'){
    //         flag = false;
    //     }
    // }
    return 0;
}