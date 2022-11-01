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
    Word init;
    Matrix m;
    POINT S;
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
    while (!compareString(currentWord,keluar))
    {
        printf("Enter Command: ");
        
        // progamm disini ya ges ya
        // check if currentword = NORTH 
        STARTWORD();
        if (compareString(currentWord,"w")){
            moveNorth(&m,&S);
            displayMap(m);
            TulisPOINT(S);
            printf("Moving North\n");
        }
        else if (compareString(currentWord,"s")){
            moveSouth(&m,&S);
            displayMap(m);
            TulisPOINT(S);
            printf("Moving South\n");
        }
        else if (compareString(currentWord,"d")){
            moveEast(&m,&S);
            displayMap(m);
            TulisPOINT(S);
            printf("Moving East\n");
        }
        else if (compareString(currentWord,"a")){
            moveWest(&m,&S);
            displayMap(m);
            TulisPOINT(S);
            printf("Moving West\n");
        }
        else{
            printf("\nWrong Command\n");
        }
        //startword yang bawah ini buat exit
    }
}