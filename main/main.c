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
    printf("================================================\n");
    printf("Masukkan Username : ");
    STARTWORD(); 
    p.username = WordToStr(currentWord);
    while (!compareString(currentWord,keluar))
    {
        printf("================================================\n");
        printf("%s di posisi: ",p.username);
        TulisPOINT(S);
        printf("Waktu: ");
        printf("\n");
        printf("Notifikasi: ");
        printf("\n");
        displayMap(m);
        printf("================================================\n");

        printf("Enter Command: ");
        STARTWORD();
        if (compareString(currentWord,"MOVE")){
            STARTWORD(); 
            if (compareString(currentWord,"NORTH")){
                moveNorth(&m,&S);
            }
            else if (compareString(currentWord,"SOUTH")){
                moveSouth(&m,&S);
            }
            else if (compareString(currentWord,"EAST")){
                moveEast(&m,&S);
            }
            else if (compareString(currentWord,"WEST")){
                moveWest(&m,&S);
            }
        }
        // press enter to continue
        printf("Press (.) to continue...");
        STARTWORD();
        system("cls");
    }
}