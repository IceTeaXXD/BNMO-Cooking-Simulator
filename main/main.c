#include <stdio.h>
#include <stdlib.h>
#include "implementasiadt.h"
//buat run pake yang bawah aja, nanti edit
//#include "../modules/adt.h"
int main (){
    //inisiasi program
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
    //KAMUS PRIMITIVE
    char keluar[NMax]="EXIT";
    char mulai[NMax]="START";
    char inputinit[NMax];
    int i;
    //KAMUS ADT
    Word titiK={".",1};
    Word init;
    Matrix m;
    POINT S;
    Word nameTemp;
    player p;
    ReadMap_FILE(&m,&S, "../modules/map/testMap.txt");
    //ALGORITMA MAIN
    printf("================================================\n");
    printf("================================================\n");
    printf("Please insert START to initiate the program\n");
    STARTWORD();
    system("cls"); 
    for (i=0; i<currentWord.Length;i++){
        inputinit[i]=currentWord.TabWord[i];
    }
    while (!compareString(currentWord,mulai))
    {
        currentWord=init;
        printf("Wrong Command\n");
        printf("Please insert START to initiate the program\n");
        STARTWORD();
        system("cls"); 
        for (i=0; i<currentWord.Length;i++){
           inputinit[i]=currentWord.TabWord[i];
        }
    }
    currentWord=init;
    while (!compareString(currentWord,keluar))
    {
        //printf("%s di posisi: ", USERNAME(p));
        TulisPOINT(S);
        displayMap(m);
        printf("Enter Command: ");
        // progamm disini ya ges ya
        // check if currentword = NORTH 
        STARTWORD();
        if (compareString(currentWord,"NORTH")){
            //system("cls");
            printf("Moving North\n");
            moveNorth(&m,&S);
        }
        else if (compareString(currentWord,"SOUTH")){
            //system("cls");
            printf("Moving South\n");
            moveSouth(&m,&S);
        }
        else if (compareString(currentWord,"EAST")){
            //system("cls");
            printf("Moving East\n");
            moveEast(&m,&S);
        }
        else if (compareString(currentWord,"WEST")){
            //system("cls");
            printf("Moving West\n");
            moveWest(&m,&S);
        }
        else{
            //system("cls");
            printf("Wrong Command\n");
        }
        currentWord=init;
    }
}