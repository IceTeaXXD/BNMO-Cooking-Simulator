// #include "../wordmachine/charmachine.c"
#include "../wordmachine/wordmachine.h"
#include "../matrix/matrix.h"
#include "../point/point.h"
#include "../food/food.h"
#include "../prioqueue/prioqueueinv.h"
#include <stdio.h>

char IntToMap(char c){
    if (c == -1){
        return ' ';
    }
    else if(c == -2){
        return 'S';
    }
    else if(c == 3){
        return 'T';
    }
    else if(c == 4){
        return 'M';
    }
    else if(c == 5){
        return 'C';
    }
    else if(c == 6){
        return 'F';
    }
    else if(c == 7){
        return 'B';
    }
    else if(c == 8){
        return 'X';
    } 
    else if(c == 9){
        return 'K';
    }
}

void displayMap(Matrix m){
    int i,j;
    for (i = 0 ; i < COL_EFF(m)+2 ; i++){
        if (i != COL_EFF(m)+1){
            printf("* ");
        }else{
            printf("*\n");
        }
    }

    for (i = 0 ; i < ROW_EFF(m) ; i++){
        printf("* ");
        for (j = 0 ; j < COL_EFF(m) ; j++){
            if (j < COL_EFF(m)){
                printf("%c ",IntToMap(MATRIXELMT(m,i,j)));
            }else{
                printf("%d",IntToMap(MATRIXELMT(m,i,j)));
            }
        }
        printf("*\n");
    }

    for (i = 0 ; i < COL_EFF(m)+2 ; i++){
        if (i != COL_EFF(m)+1){
            printf("* ");
        }else{
            printf("*\n");
        }
    }
}            
        
void ReadMap_FILE(Matrix *m, POINT *S, char filename[]){
    // read file
    int i,j,k;
    STARTWORD_FILE(filename);
    // the first line is number of row and cols
    int row,col;
    row = WordToInt(currentWord);
    ADVWORD();
    col = WordToInt(currentWord);
    ADVWORD();

    // create matrix
    createMatrix(row,col,m);

    for (i = 0 ; i < row ; i++){
        for (j = 0; j < col ; j++){
            if (currentWord.TabWord[j] == '#'){
                MATRIXELMT(*m,i,j) = -1;
            }else if (currentWord.TabWord[j] == 'S'){
                MATRIXELMT(*m,i,j) = -2;
                CreatePoint(&*S, j, i);
            }else if (currentWord.TabWord[j] == 'T'){
                MATRIXELMT(*m,i,j) = 3;
            }else if (currentWord.TabWord[j] == 'M'){
                MATRIXELMT(*m,i,j) = 4;
            }else if (currentWord.TabWord[j] == 'C'){
                MATRIXELMT(*m,i,j) = 5;
            }else if (currentWord.TabWord[j] == 'F'){
                MATRIXELMT(*m,i,j) = 6;
            }else if (currentWord.TabWord[j] == 'B'){
                MATRIXELMT(*m,i,j) = 7;
            }else if (currentWord.TabWord[j] == 'X'){
                MATRIXELMT(*m,i,j) = 8;
            }else if (currentWord.TabWord[j] == 'K'){
                MATRIXELMT(*m,i,j) = 9;
            }
            
        }
        if (i < row-1){
            ADVWORD();
        }
    }
}

void moveNorth(Matrix *m, POINT *S, boolean *commandValid)
{
    if(MATRIXELMT(*m, Ordinat(*S)-1, Absis(*S)) == -1){
        Ordinat(*S)--;
        MATRIXELMT(*m, Ordinat(*S), Absis(*S)) = -2;
        MATRIXELMT(*m, Ordinat(*S)+1, Absis(*S)) = -1;
    }else{
        *commandValid = false;
        printf("Obstacle Ahead!\n");
    }
}

void moveSouth(Matrix *m, POINT *S, boolean *commandValid)
{
    if(MATRIXELMT(*m, Ordinat(*S)+1, Absis(*S)) == -1){
        Ordinat(*S)++;
        MATRIXELMT(*m, Ordinat(*S), Absis(*S)) = -2;
        MATRIXELMT(*m, Ordinat(*S)-1, Absis(*S)) = -1;
    }else{
        *commandValid = false;
        printf("Obstacle Ahead!\n");
    }
}

void moveEast(Matrix *m, POINT *S, boolean *commandValid)
{
    if(MATRIXELMT(*m, Ordinat(*S), Absis(*S)+1) == -1){
        Absis(*S)++;
        MATRIXELMT(*m, Ordinat(*S), Absis(*S)) = -2;
        MATRIXELMT(*m, Ordinat(*S), Absis(*S)-1) = -1;
    }else{
        *commandValid = false;
        printf("Obstacle Ahead!\n");
    }
}

void moveWest(Matrix *m, POINT *S, boolean *commandValid)
{
    if(MATRIXELMT(*m, Ordinat(*S), Absis(*S)-1) == -1){
        Absis(*S)--;
        MATRIXELMT(*m, Ordinat(*S), Absis(*S)) = -2;
        MATRIXELMT(*m, Ordinat(*S), Absis(*S)+1) = -1;
    }else{
        *commandValid = false;
        printf("Obstacle Ahead!\n");
    }
}

boolean isAdjacentToTelephone(Matrix m, POINT S){ // BUY
    return (MATRIXELMT(m, Ordinat(S)-1, Absis(S)) == 3 || MATRIXELMT(m, Ordinat(S)+1, Absis(S)) == 3 || MATRIXELMT(m, Ordinat(S), Absis(S)-1) == 3 || MATRIXELMT(m, Ordinat(S), Absis(S)+1) == 3);
}

boolean isAdjacentToMix(Matrix m, POINT S){ // MIX
    return (MATRIXELMT(m, Ordinat(S)-1, Absis(S)) == 4 || MATRIXELMT(m, Ordinat(S)+1, Absis(S)) == 4 || MATRIXELMT(m, Ordinat(S), Absis(S)-1) == 4 || MATRIXELMT(m, Ordinat(S), Absis(S)+1) == 4);
}

boolean isAdjacentToChop(Matrix m, POINT S){ // CHOP
    return (MATRIXELMT(m, Ordinat(S)-1, Absis(S)) == 5 || MATRIXELMT(m, Ordinat(S)+1, Absis(S)) == 5 || MATRIXELMT(m, Ordinat(S), Absis(S)-1) == 5 || MATRIXELMT(m, Ordinat(S), Absis(S)+1) == 5);
}

boolean isAdjacentToFry(Matrix m, POINT S){ // FRY
    return (MATRIXELMT(m, Ordinat(S)-1, Absis(S)) == 6 || MATRIXELMT(m, Ordinat(S)+1, Absis(S)) == 6 || MATRIXELMT(m, Ordinat(S), Absis(S)-1) == 6 || MATRIXELMT(m, Ordinat(S), Absis(S)+1) == 6);
}

boolean isAdjacentToBoil(Matrix m, POINT S){ // BOIL
    return (MATRIXELMT(m, Ordinat(S)-1, Absis(S)) == 7 || MATRIXELMT(m, Ordinat(S)+1, Absis(S)) == 7 || MATRIXELMT(m, Ordinat(S), Absis(S)-1) == 7 || MATRIXELMT(m, Ordinat(S), Absis(S)+1) == 7);
}

boolean isAdjacentToKulkas(Matrix m, POINT S){ // FRIDGE
    return (MATRIXELMT(m, Ordinat(S)-1, Absis(S)) == 9 || MATRIXELMT(m, Ordinat(S)+1, Absis(S)) == 9 || MATRIXELMT(m, Ordinat(S), Absis(S)-1) == 9 || MATRIXELMT(m, Ordinat(S), Absis(S)+1) == 9);
}

void createKulkas(int row, int col, Matrix *kulkas){
    createMatrix(row, col, kulkas);
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            MATRIXELMT(*kulkas, i, j) = -1;
        }
    }
}

void accessKulkas(Matrix *kulkas, POINT *cursor){
    int tempx,tempy;
    tempx = 0;
    tempy = 0;
    boolean spawn = false;
    int i=0,j=0;
    while (i < ROW_EFF(*kulkas) && MATRIXELMT(*kulkas,i,j) != -1)
    {
        while (j < COL_EFF(*kulkas) && MATRIXELMT(*kulkas,i,j) != -1){
            j++;
        }
        if (MATRIXELMT(*kulkas,i,j) != -1){
            j=0;
            i++;
        }
    }
    if (MATRIXELMT(*kulkas,i,j) == -1){
        spawn = true;
    }
    if (!spawn){
        printf("full\n");
    } else {
        CreatePoint(cursor,j,i);
    }
    j=Absis(*cursor);
    i=Ordinat(*cursor);
    MATRIXELMT(*kulkas, i,j)=-2;
}


char IntToKulkas(char c){
    if (c == -1){
        return ' ';
    } else if (c == -2){
        return (char) 206;
    } else {
        return 'X';
    }
}

void displayKulkas(Matrix m){
    int i,j;
    printf("KULKAS\n");
    for (i = 0 ; i < COL_EFF(m)+2 ; i++){
        if (i != COL_EFF(m)+1){
            printf("* ");
        }else{
            printf("*\n");
        }
    }

    for (i = 0 ; i < ROW_EFF(m) ; i++){
        printf("* ");
        for (j = 0 ; j < COL_EFF(m) ; j++){
            if (MATRIXELMT(m, i, j)==-1){
                printf("%c ",IntToKulkas(MATRIXELMT(m,i,j)));
            } else {
                printf("%c ",IntToKulkas(MATRIXELMT(m,i,j)));
            }
        }
        printf("*\n");
    }

    for (i = 0 ; i < COL_EFF(m)+2 ; i++){
        if (i != COL_EFF(m)+1){
            printf("* ");
        }else{
            printf("*\n");
        }
    }
} 

void insertResidentEvilInv(Matrix *kulkas, food pud, POINT *cursor){
    int insert=FoodId(pud);
    int i, j, tempx, tempy;
    int ySize=FoodSizeY(pud);
    int xSize=FoodSizeX(pud);
    tempx = Absis(*cursor);
    tempy = Ordinat(*cursor);
    boolean obstacle = false;
    //checking space
    for (i = tempy; i < tempy+ySize; i++){
        for (j = tempx; j < tempx+xSize; j++){
            if (MATRIXELMT(*kulkas, i, j)!= -1 && MATRIXELMT(*kulkas,i,j)!=-2){
                obstacle = true;
            }
        }
    }
    if (obstacle){
        printf("Invalid space\n");
    } else {
        //insertion
        for (i = tempy; i<tempy+ySize;i++){
            for (j = tempx; j<tempx+xSize;j++){
                MATRIXELMT(*kulkas, i, j) = insert;
            }
        }
        //respawning
        boolean spawn = false;
        int i=0,j=0;
        while (i < ROW_EFF(*kulkas) && MATRIXELMT(*kulkas,i,j) != -1)
        {
            while (j < COL_EFF(*kulkas) && MATRIXELMT(*kulkas,i,j) != -1){
                j++;
            }
            if (MATRIXELMT(*kulkas,i,j) != -1){
                j=0;
                i++;
            }
        }
        if (MATRIXELMT(*kulkas,i,j) == -1){
            spawn = true;
        }
        if (!spawn){
            printf("full\n");
        } else {
            Ordinat(*cursor) = i;
            Absis(*cursor) = j;
        }
    }
    displayKulkas(*kulkas);
    TulisPOINT(*cursor);
}

void removeIdFoodResidentEvil(Matrix *kulkas, food pud){
    int remove = FoodId(pud);
    int i=0, j=0;
    boolean found = false;
    while (i < ROW_EFF(*kulkas) && MATRIXELMT(*kulkas,i,j) != remove){
        while (j < COL_EFF(*kulkas) && MATRIXELMT(*kulkas,i,j) != remove){
            j++;
        }
        if (MATRIXELMT(*kulkas,i,j) != remove){
            j=0;
            i++;
        }
    }
    if (MATRIXELMT(*kulkas,i,j) == remove){
        found = true;
    }
    int spotrow=i;
    int spotcol=j;
    for (i = spotrow; i < spotrow+FoodSizeY(pud); i++){
        for (j = spotcol; j < spotcol+FoodSizeX(pud); j++){
            MATRIXELMT(*kulkas,i,j)=-1;
        } 
    }
}

void FRIDGE(Prioqueueinv *inventory, Matrix *kulkas, ListFoodStatik *listFridge){
    POINT cursor;
    food pud;
    int i, j, tempx, tempy;
    int idx;
    boolean bool=true;
    // createKulkas(10, 20, &kulkas);
    // printf("input: ");
    // scanf("%d", &insert);
    accessKulkas(kulkas, &cursor);
    system("cls");
    displayKulkas(*kulkas);
    TulisPOINT(cursor);
    boolean flag = true;
while (flag){
        printf("%c Movement: WASD\n",201);
        printf("%c Action: \n",204);
        printf("%c%c PLACE\n",204,205);
        printf("%c%c TAKE\n",204,205);
        printf("%c Exit Fridge\n",204);
        printf("%c%c CANCEL\n",200,205);
        printf("Enter Command: ");
        STARTSENTENCE();
        if (compareString(currentWord,"W")){
            system("cls");
            moveNorth(kulkas, &cursor, &bool);
            displayKulkas(*kulkas);
            TulisPOINT(cursor);
        }
        else if (compareString(currentWord,"S")){
            system("cls");
            moveSouth(kulkas, &cursor, &bool);
            displayKulkas(*kulkas);
            TulisPOINT(cursor);
        }
        else if (compareString(currentWord,"A")){
            system("cls");
            moveWest(kulkas, &cursor, &bool);
            displayKulkas(*kulkas);
            TulisPOINT(cursor);
        }
        else if (compareString(currentWord,"D")){
            system("cls");
            moveEast(kulkas, &cursor, &bool);
            displayKulkas(*kulkas);
            TulisPOINT(cursor);
        } else if (compareString(currentWord,"PLACE")){
            system("cls");
            displayKulkas(*kulkas);
            PrintInvPrio(*inventory);
            printf("Pilih makanan yang ingin dimasukkan : ");
            STARTSENTENCE();
            if(compareString(currentWord,"CANCEL")) {
                goto CANCELING;
            } else {
                idx=WordToInt(currentWord)-1;
                while (idx<0||idx>NBElmt_Prioqueue(*inventory)){
                    printf("Invalid input atau inventory kosong\n");
                    printf("Type CANCEL to cancel storing food\n");
                    printf("Enter Command : ");
                    STARTSENTENCE();
                    if (compareString(currentWord,"CANCEL")){
                        goto CANCELING;
                    }
                    idx=WordToInt(currentWord)-1;
                }
                pud=Elmt(*inventory,idx);
                insertLast_ListFoodStatik(listFridge, pud);
                Dequeue_idx_Prioqueue(inventory,idx);
                insertResidentEvilInv(kulkas,pud,&cursor);
                flag = false;
            }
        }else if (compareString(currentWord,"TAKE")){
            system("cls");
            displayKulkas(*kulkas);
            printList_ListFoodStatik(*listFridge);
            if (isEmpty_ListFoodStatik(*listFridge)){
                printf("Kulkas Kosong\n");
                goto CANCELING;
            } else {
                printf("Pilih makanan yang ingin diambil : ");
                STARTSENTENCE();
                if(compareString(currentWord,"CANCEL")) {
                    goto CANCELING;
                } else {
                    idx=WordToInt(currentWord)-1;
                    while (idx<0||idx>NBElmt_Prioqueue(*inventory)){
                        printf("Invalid input atau kulkas kosong\n");
                        printf("Type CANCEL to cancel taking food\n");
                        printf("Enter Command : ");
                        STARTSENTENCE();
                        if (compareString(currentWord,"CANCEL")){
                            goto CANCELING;
                        }
                        idx=WordToInt(currentWord)-1;
                    }
                    deleteAt_ListFoodStatik(listFridge, &pud,idx);
                    removeIdFoodResidentEvil(kulkas,pud);
                    displayKulkas(*kulkas);
                    Enqueue_Prioqueue(inventory, pud);
                    MATRIXELMT(*kulkas,Ordinat(cursor),Absis(cursor))=-1;
                    flag = false;
                }
            }
        }
        else if (compareString(currentWord,"CANCEL")){
    CANCELING:
            MATRIXELMT(*kulkas,Ordinat(cursor),Absis(cursor))=-1;
            flag = false;
        }
    }
}
// boolean isTelepon (Matrix m, POINT S)
// {
//     if (MATRIXELMT(m, Ordinat(S) == 1, Absis(S) == 3) || (MATRIXELMT(m, Ordinat(S) == 0, Absis(S) == 4)) || (MATRIXELMT(m, Ordinat(S) == 1, Absis(S) == 5)) || (MATRIXELMT(m, Ordinat(S) == 2, Absis(S) == 4))){
//         return true;
//     }else{
//         return false;
//     }
// }

// boolean isMix (Matrix m, POINT S)
// {
//     if (MATRIXELMT(m, Ordinat(S) == 2, Absis(S) == 0) || (MATRIXELMT(m, Ordinat(S) == 1, Absis(S) == 1)) || (MATRIXELMT(m, Ordinat(S) == 3, Absis(S) == 1)) || (MATRIXELMT(m, Ordinat(S) == 2, Absis(S) == 2))){
//         return true;
//     }else{
//         return false;
//     }
// }

// boolean isChop (Matrix m, POINT S)
// {
//     if (MATRIXELMT(m, Ordinat(S) == 6, Absis(S) == 7) || (MATRIXELMT(m, Ordinat(S) == 5, Absis(S) == 8)) || (MATRIXELMT(m, Ordinat(S) == 6, Absis(S) == 9)) || (MATRIXELMT(m, Ordinat(S) == 7, Absis(S) == 8))){
//         return true;
//     }else{
//         return false;
//     }
// }

// boolean iSFry (Matrix m, POINT S)
// {   
//     if (MATRIXELMT(m, Ordinat(S) == 7, Absis(S) == 5) || (MATRIXELMT(m, Ordinat(S) == 6, Absis(S) == 6)) || (MATRIXELMT(m, Ordinat(S) == 7, Absis(S) == 7)) || (MATRIXELMT(m, Ordinat(S) == 8, Absis(S) == 6))){
//         return true;
//     }else{
//         return false;
//     }
// }

// boolean isBuy (Matrix m, POINT S)
// {
//     if (MATRIXELMT(m, Ordinat(S) == 9, Absis(S) == 5) || (MATRIXELMT(m, Ordinat(S) == 8, Absis(S) == 6)) || (MATRIXELMT(m, Ordinat(S) == 9, Absis(S) == 7))){
//         return true;
//     }else{
//         return false;
//     }
// }