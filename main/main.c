#include <stdio.h>
#include <stdlib.h>
#include "implementasiadt.h"
//buat run pake yang bawah aja, nanti edit
//#include "../modules/adt.h"
void initiate(){
    //system("cls");
    printf("                    . .:.:.:.:. .:\\     /:. .:.:.:.:. ,\n");
    printf("               .-._  `..:.:. . .:.:`- -':.:. . .:.:.,'  _.-.\n");
    printf("              .:.:.`-._`-._..-''_...---..._``-.._.-'_.-'.:.:.\n");
    printf("           .:.:. . .:_.`' _..-''._________,``-.._ `.._:. . .:.:.\n");
    printf("        .:.:. . . ,-'_.-''      ||_-(O)-_||      ``-._`-. . . .:.:.\n");
    printf("       .:. . . .,'_.'           '---------'           `._`.. . . .:.\n");
    printf("     :.:. . . ,','               _________               `.`. . . .:.:\n");
    printf("    `.:.:. .,','            _.-''_________``-._            `._.     _.'\n");
    printf("  -._  `._./ /            ,'_.-'' ,       ``-._`.          ,' '`:..'  _.-\n");
    printf(" .:.:`-.._' /           ,','                   `.`.       /'  '  \\\\.-':.:.\n");
    printf(" :.:. . ./ /          ,','               ,       `.`.    / '  '  '\\\\. .:.:\n");
    printf(":.:. . ./ /          / /    ,                      \\ \\  :  '  '  ' \\\\. .:.:\n");
    printf(".:. . ./ /          / /            ,          ,     \\ \\ :  '  '  ' '::. .:.\n");
    printf(":. . .: :    o     / /            WELCOME            \\ ;'  '  '  ' ':: . .:\n");
    printf(".:. . | |   /_\\   : :     ,        TO C          ,    : '  '  '  ' ' :: .:.\n");
    printf(":. . .| |  ((<))  | |,          ,UNIVERSES            |\'__',-._.' ' ||. .:\n");
    printf(".:.:. | |   `-'   | |---....____                      | ,---\\/--/  ' ||:.:.\n");
    printf("------| |         : :    ,.     ```--..._   ,         |''  '  '  ' ' ||----\n");
    printf("_...--. |  ,       \\ \\             ,.    `-._     ,  /: '  '  '  ' ' ;;..._\n");
    printf(":.:. .| | -O-       \\ \\    ,.                `._    / /:'  '  '  ' ':: .:.:\n");
    printf(".:. . | |_(`__       \\ \\                        `. / / :'  '  '  ' ';;. .:.\n");
    printf(":. . .<' (_)  `>      `.`.          ,.    ,.     ,','   \\  '  '  ' ;;. . .:\n");
    printf(".:. . |):-.--'(         `.`-._  ,.           _,-','      \\ '  '  '//| . .:.\n");
    printf(":. . .;)()(__)(___________`-._`-.._______..-'_.-'_________\'  '  //_:. . .:\n");
    printf(".:.:,' \\/\\/--\\/--------------------------------------------`._',;'`. `.:.:.\n");
    printf(":.,' ,' ,'  ,'  /   /   /   ,-------------------.   \\   \\   \\  `. `.`. `..:\n");
    printf(",' ,'  '   /   /   /   /   //                   \\\\   \\   \\   \\   \\  ` `..:\n");
    printf("================================================\n");
    printf("================================================\n");
}
void terminate(){
    system("cls"); 
    printf("                    . .:.:.:.:. .:\\     /:. .:.:.:.:. ,\n");
    printf("               .-._  `..:.:. . .:.:`- -':.:. . .:.:.,'  _.-.\n");
    printf("              .:.:.`-._`-._..-''_...---..._``-.._.-'_.-'.:.:.\n");
    printf("           .:.:. . .:_.`' _..-''._________,``-.._ `.._:. . .:.:.\n");
    printf("        .:.:. . . ,-'_.-''      ||_-(O)-_||      ``-._`-. . . .:.:.\n");
    printf("       .:. . . .,'_.'           '---------'           `._`.. . . .:.\n");
    printf("     :.:. . . ,','               _________               `.`. . . .:.:\n");
    printf("    `.:.:. .,','            _.-''_________``-._            `._.     _.'\n");
    printf("  -._  `._./ /            ,'_.-'' ,       ``-._`.          ,' '`:..'  _.-\n");
    printf(" .:.:`-.._' /           ,','                   `.`.       /'  '  \\\\.-':.:.\n");
    printf(" :.:. . ./ /          ,','               ,       `.`.    / '  '  '\\\\. .:.:\n");
    printf(":.:. . ./ /          / /    ,                      \\ \\  :  '  '  ' \\\\. .:.:\n");
    printf(".:. . ./ /          / /            ,          ,     \\ \\ :  '  '  ' '::. .:.\n");
    printf(":. . .: :    o     / /                               \\ ;'  '  '  ' ':: . .:\n");
    printf(".:. . | |   /_\\   : :     ,     THANK YOU        ,    : '  '  '  ' ' :: .:.\n");
    printf(":. . .| |  ((<))  | |,          SINCERELY!!           |\'__',-._.' ' ||. .:\n");
    printf(".:.:. | |   `-'   | |---....____                      | ,---\\/--/  ' ||:.:.\n");
    printf("------| |         : :    ,.     ```--..._   ,         |''  '  '  ' ' ||----\n");
    printf("_...--. |  ,       \\ \\             ,.    `-._     ,  /: '  '  '  ' ' ;;..._\n");
    printf(":.:. .| | -O-       \\ \\    ,.                `._    / /:'  '  '  ' ':: .:.:\n");
    printf(".:. . | |_(`__       \\ \\                        `. / / :'  '  '  ' ';;. .:.\n");
    printf(":. . .<' (_)  `>      `.`.          ,.    ,.     ,','   \\  '  '  ' ;;. . .:\n");
    printf(".:. . |):-.--'(         `.`-._  ,.           _,-','      \\ '  '  '//| . .:.\n");
    printf(":. . .;)()(__)(___________`-._`-.._______..-'_.-'_________\'  '  //_:. . .:\n");
    printf(".:.:,' \\/\\/--\\/--------------------------------------------`._',;'`. `.:.:.\n");
    printf(":.,' ,' ,'  ,'  /   /   /   ,-------------------.   \\   \\   \\  `. `.`. `..:\n");
    printf(",' ,'  '   /   /   /   /   //                   \\\\   \\   \\   \\   \\  ` `..:\n");
}

int main (){
    //inisiasi program
    //KAMUS PRIMITIVE
    initiate();
    char keluar[NMax]="EXIT";
    char mulai[NMax]="START";
    char input[NMax];
    int i;
    boolean tambahTime;
    //KAMUS ADT
    Word titiK={".",1};
    Word init;
    Matrix m;
    TIME T;
    Word nameTemp;
    player p;
    ReadMap_FILE(&m,&LOC(p), "../modules/map/testMap.txt");

    // Delivery
    CreatePlayer(&p);
    Prioqueueinv Delivery;
    ListFoodStatik Foods;
    CreateListFoodStatik(&Foods);
    MakeEmpty_Prioqueue(&Delivery,1000);
    ReadFood_FILE("../cfg/food.txt", &Foods);


    // GAME TIME
    TIME GameTime;
    CreateTime(&GameTime, 0, 0, 0);

    //ALGORITMA MAIN
    printf("Please insert START to initiate the program\n");
    STARTSENTENCE();
    system("cls"); 
    while (!compareString(currentWord,mulai))
    {
        initiate();
        currentWord=init;
        printf("Wrong Command\n");
        printf("Please insert START to initiate the program\n");
        STARTSENTENCE();
        system("cls"); 
    }
    currentWord=init;
    printf("================================================\n");
    printf("Masukkan Username : ");
    STARTSENTENCE();
    p.username = WordToStr(currentWord);
    while (!compareString(currentWord,keluar))
    {
        tambahTime = true;
        currentWord=init;
        printf("================================================\n");
        printf("%s di posisi: ",p.username);
        TulisPOINT(LOC(p));
        printf("Waktu: ");
        TulisTIME2(GameTime);
        printf("\n");
        printf("Notifikasi: ");
        printf("\n");
        displayMap(m);
        printf("================================================\n");
        printf("List of Command\n");
        printf("%c Movement:\n",201);
        printf("%c%c MOVE NORTH\n",204,205);
        printf("%c%c MOVE EAST\n",204,205);
        printf("%c%c MOVE SOUTH\n",204,205);
        printf("%c%c MOVE WEST\n",204,205);
        //prinf buat command kalo ke M,T,C,F,B,DLL);
        printf("%c Others:\n",204);
        printf("%c%c BUY\n",204,205);
        printf("%c%c DELIVERY\n",204,205);
        printf("%c%c INVENTORY\n",204,205);
        printf("%c%c WAIT <JAM> <MENIT>\n",204,205);
        printf("%c Exit Program\n",204);
        printf("%c%c EXIT\n",200,205);
        
        printf("\nENTER COMMAND: ");
        STARTSENTENCE(); 
        if (compareString(currentWord,"MOVE NORTH")){
            moveNorth(&m,&LOC(p),&tambahTime);
        }
        else if (compareString(currentWord,"MOVE SOUTH")){
            moveSouth(&m,&LOC(p),&tambahTime);
        }
        else if (compareString(currentWord,"MOVE EAST")){
            moveEast(&m,&LOC(p),&tambahTime);
        }
        else if (compareString(currentWord,"MOVE WEST")){
            moveWest(&m,&LOC(p),&tambahTime);
        } 
        else if (compareString(currentWord,"DELIVERY")){
            tambahTime = false;
            PrintPrioqueueinv(Delivery);
        } 
        else if (compareString(currentWord,"INVENTORY")){
            tambahTime = false;
            PrintInvPrio(p.inventory);
        }
        
        else if (compareString(currentWord,"BUY")){
            BUY(Foods, &Delivery);
        }
        // WAIT 10 11
        else if (compareString(currentWord,"WAIT")){
            currentWord = init;
            printf("Masukkan jam: ");
            STARTSENTENCE();
            int jam = WordToInt(currentWord);
            printf("Masukkan menit: ");
            STARTSENTENCE();
            int menit = WordToInt(currentWord);
            timeLogic(0, jam, menit, &GameTime, &Delivery, &p.inventory);
            tambahTime = false;
        }
        else if (compareString(currentWord,"EXIT")){
            printf("Thank you for playing!\n");
            printf("See you next time!\n");
            break;
        }

        else if (compareString(currentWord,keluar)){
            terminate();
            break;
        }
        else {
            tambahTime = false;
            printf("Unidentified Command\n");
        }
        if (tambahTime){
            timeLogic(0,0,1,&GameTime,&Delivery,&p.inventory);
        }
        currentWord=init;
        printf("press <enter> to continue\n");
        STARTSENTENCE();
        system("cls");
    }
}