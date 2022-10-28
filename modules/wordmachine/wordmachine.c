#include <stdio.h>
#include "wordmachine.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = CHARMARK */
{
   while (currentChar == BLANK || currentChar == '\n') {
      ADV();
   }
}
void STARTWORD()
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = CHARMARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
   START();
   IgnoreBlanks();
   if (currentChar == CHARMARK){
      EndWord = true;
   }
   else{
      EndWord = false;
      CopyWord();
   }
}
void STARTWORD_FILE(char filename[])
{
   START_FILE(filename);
   IgnoreBlanks();
   if (currentChar == CHARMARK){
      EndWord = true;
   }
   else{
      EndWord = false;
      ADVWORD();
   }
}

void ADVWORD()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin CHARMARK
          Jika currentChar = CHARMARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
{
   IgnoreBlanks();
   if (currentChar == CHARMARK){
      EndWord = true;
   }
   else{
      CopyWord();
      IgnoreBlanks();
   }
}

void CopyWord()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = CHARMARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
   int i = 0;
   while (currentChar != CHARMARK && currentChar != BLANK && currentChar != LineMARK){
      currentWord.TabWord[i] = currentChar;
      ADV();
      i++;
   }

   if (i > NMax){
      currentWord.Length = NMax;
   }

   else{
      currentWord.Length = i;
   }
}

int WordToInt(Word string){
   int result = 0;
   int i;
   for (i=0; i<string.Length; i++){
      result = result * 10 + (string.TabWord[i] - 48);
   }

   if (result < 0){
      int digit = 1;
      for (i=0; i<string.Length-1; i++){
         digit = digit * 10;
      }
      result += 38 * digit;
   }

   return result;
}

void ADVNEWLINE(){
   
    Word EMPTY = {"", 0};
    currentWord = EMPTY;
    if(currentChar == CHARMARK){
        EndWord = false;
        ADV();
        CopyWord();
    }
}