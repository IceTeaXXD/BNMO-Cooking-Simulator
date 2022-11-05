#include <stdio.h>
#include <stdlib.h>
#include "implementasiadt.h"
//buat run pake yang bawah aja, nanti edit
//#include "../modules/adt.h"
void initiate(){
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
    //KAMUS ADT
    Word titiK={".",1};
    Word init;
    Matrix m;
    TIME T;
    Word nameTemp;
    player p;
    ReadMap_FILE(&m,&LOC(p), "../modules/map/testMap.txt");
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
    currentWord=init;
    while (!compareString(currentWord,keluar))
    {
        currentWord=init;
        printf("================================================\n");
        printf("%s di posisi: ",p.username);
        TulisPOINT(LOC(p));
        printf("Waktu: ");
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
        printf("%c Exit Program\n",204);
        printf("%c%c EXIT\n",200,205);
        printf("Enter Command: ");
        STARTSENTENCE(); 
        if (compareString(currentWord,"MOVE NORTH")){
            moveNorth(&m,&LOC(p));
        }
        else if (compareString(currentWord,"MOVE SOUTH")){
            moveSouth(&m,&LOC(p));
        }
        else if (compareString(currentWord,"MOVE EAST")){
            moveEast(&m,&LOC(p));
        }
        else if (compareString(currentWord,"MOVE WEST")){
            moveWest(&m,&LOC(p));
        } 
        else if (compareString(currentWord,keluar)){
            terminate();
            break;
        } else {
            printf("Unidentified Command\n");
        }
        currentWord=init;
        printf("press <enter> to continue\n");
        STARTSENTENCE();
        system("cls");
    }
}