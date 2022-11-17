#include <stdio.h>
#include <stdlib.h>
#include "implementasiadt.h"
//buat run pake yang bawah aja, nanti edit
//#include "../modules/adt.h"
void initiate(){
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
    int i, idxNotif, jenisNotif, banyakNotif;
    boolean tambahTime;
    //KAMUS ADT
    Word titiK={".",1};
    Word init;
    Matrix m;
    TIME T;
    Word nameTemp;
    player p;CreatePlayer(&p);
    food foodAffected;
    extern boolean adaNotif;
    extern ListStatik jenis2Notif;
    extern ListFoodStatik notif;
    ReadMap_FILE(&m,&LOC(p), "../modules/map/testMap.txt");
    //Constructor Tree
    Matrix n;
    ListTreeStatik lt;
    CreateListTreeStatik(&lt);
    createMatrix(100,100,&n);
    int N = Treemachine("../cfg/resep.txt",&n);
    Tree tree;
    matrixToTree(n,N,&tree);
    insertLast_ListTreeStatik(&lt, tree);
    
    // Delivery
    Prioqueueinv Delivery;
    ListFoodStatik Foods;CreateListFoodStatik(&Foods);
    MakeEmpty_Prioqueue(&Delivery,1000);
    ReadFood_FILE("../cfg/food.txt", &Foods);
    CreateListFoodStatik(&notif);
    CreateListStatik(&jenis2Notif);
    
    //FoodTIME(Processing)
    Prioqueueinv Process;
    MakeEmpty_Prioqueue(&Process,100);
    
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
        if (adaNotif) {
            printf("Notifikasi: \n");
            // printList_ListFoodStatik(notif);printList_ListStatik(jenis2Notif);
            // printf("ada %d notif\n", listLength_ListFoodStatik(notif));
            banyakNotif = listLength_ListFoodStatik(notif);
            for (idxNotif = 0; idxNotif < banyakNotif; idxNotif++){
                printf("   %d. ",idxNotif+1);
                deleteFirst_ListStatik(&jenis2Notif, &jenisNotif);
                deleteFirst_ListFoodStatik(&notif, &foodAffected);
                    switch (jenisNotif)
                    {
                    case 1:
                        PrintWord(FoodName(foodAffected)); printf(" kedaluwarsa..:(\n");
                        break;
                    case 2:
                        PrintWord(FoodName(foodAffected)); printf(" telah diterima oleh %s!\n",USERNAME(p));
                        break;
                    case 3:
                        PrintWord(FoodName(foodAffected)); printf(" kedaluwarsa! Kamu kelamaan..:(\n");
                        break;
                    case 4:
                        PrintWord(FoodName(foodAffected)); printf(" telah selesai di "); PrintWord(FoodAction(foodAffected)); printf("!\n");
                        break;
                    }
            }
            CreateListFoodStatik(&notif);
            CreateListStatik(&jenis2Notif);
            adaNotif = false;
        } else {
            printf("Notifikasi: -"); 
        }
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
        printf("%c Cooking:\n",204);
        printf("%c%c BUY\n",204,205);
        printf("%c%c CHOP\n",204,205);
        printf("%c%c FRY\n",204,205);
        printf("%c%c BOIL\n",204,205);
        printf("%c%c MIX\n",204,205);
        printf("%c Others:\n",204);
        printf("%c%c WAIT\n",204,205);
        printf("%c%c DELIVERY\n",204,205);
        printf("%c%c INVENTORY\n",204,205);
	    printf("%c%c CATALOG\n",204,205);
        printf("%c Exit Program\n",204);
        
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
        } else if (compareString(currentWord,"COOK"))
        {
            tambahTime = false;
            PrintCookPrio(Process);
        }
        
        else if (compareString(currentWord,"CATALOG")){
            printf("\nList Makanan :\n");
            tambahTime = false;
            printList_ListFoodStatik(Foods);
        }
        else if (compareString(currentWord,"MIX")) {
            if (isAdjacentToMix){
                MIX(&INVENTORY(p),Foods, tree, &Process);
            }
            else{
                printf("Player tidak dalam radius Mix (M)\n");
            }
        }
        else if (compareString(currentWord,"BUY")){
            if(isAdjacentToTelephone(m,p.loc)){
                BUY(Foods, &Delivery);
            }
            else{
                tambahTime = false;
                printf("Player tidak dalam radius telephone (T)\n");
            }
        } 
        else if (compareString(currentWord,"CHOP")){
            if(isAdjacentToChop(m,p.loc)){
                CHOP(&INVENTORY(p),Foods, tree, &Process);
            } else {
                tambahTime=false;
                printf("Player tidak dalam radius Chop (C)\n");
            }
        } 
        else if (compareString(currentWord,"BOIL")){
            if(isAdjacentToBoil(m,p.loc)){
                BOIL(&INVENTORY(p),Foods, tree, &Process);
            } else {
                tambahTime=false;
                printf("Player tidak dalam radius Boil (B)\n");
            }
        } 
        else if (compareString(currentWord,"FRY")){
            if(isAdjacentToFry(m,p.loc)){
                FRY(&INVENTORY(p),Foods, tree, &Process);
            } else {
                tambahTime=false;
                printf("Player tidak dalam radius Fry (F)\n");
            }
        }    
        else if (currentWord.TabWord[0] == 'W' && currentWord.TabWord[1] == 'A' && currentWord.TabWord[2] == 'I' && currentWord.TabWord[3] == 'T'){
            int jam, menit;
            if (CharIsInt(currentWord.TabWord[5]) && CharIsInt(currentWord.TabWord[6]) && CharIsInt(currentWord.TabWord[8]) && CharIsInt(currentWord.TabWord[9])){
                jam = (currentWord.TabWord[5] - '0') * 10 + (currentWord.TabWord[6] - '0');
                menit = (currentWord.TabWord[8] - '0') * 10 + (currentWord.TabWord[9] - '0');
            }
            else if (CharIsInt(currentWord.TabWord[5]) && CharIsInt(currentWord.TabWord[7]) && CharIsInt(currentWord.TabWord[8])){
                jam = (currentWord.TabWord[5] - '0');
                menit = (currentWord.TabWord[7] - '0') * 10 + (currentWord.TabWord[8] - '0');
            }
            else if (CharIsInt(currentWord.TabWord[5]) && CharIsInt(currentWord.TabWord[6]) && CharIsInt(currentWord.TabWord[8])){
                jam = (currentWord.TabWord[5] - '0') * 10 + (currentWord.TabWord[6] - '0');
                menit = (currentWord.TabWord[8] - '0');
            }
            else if (CharIsInt(currentWord.TabWord[5]) && CharIsInt(currentWord.TabWord[7])){
                jam = (currentWord.TabWord[5] - '0');
                menit = (currentWord.TabWord[7] - '0');
            }
            else{
                printf("Format Masukkan Waktu Salah!\n");
                jam = 0;
                menit = 0;
            }
            printf("Waktu bertambah sebanyak %d jam dan %d menit!\n", jam, menit);
            timeLogic(0, jam, menit, &GameTime, &Delivery, &p.inventory,&Process);
            tambahTime = false;
        }
        else if (compareString(currentWord,"EXIT")){
            printf("Thank you for playing!\n");
            printf("See you next time!\n");
            break;
        }
        else {
            tambahTime = false;
            printf("Unidentified Command\n");
        }
        if (tambahTime){
            timeLogic(0,0,1,&GameTime,&Delivery,&p.inventory,&Process);
        }
        printf("press <enter> to continue\n");
        STARTSENTENCE();
        system("cls");
    }
}