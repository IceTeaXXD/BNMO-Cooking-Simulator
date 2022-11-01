#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"
#include "charmachine.c"

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

Word stringToWord(char str[], int len)
{
    int i;
    Word strWord;

    strWord.Length = len;
    for (i = 0; i < len; i++)
    {
        strWord.TabWord[i] = str[i];
    }

    return strWord;
}

/*membandingkan string*/
boolean compareString(Word str1, char str2[])
{
    int i;
   //  if (str1.Length != str2.Length)
   //  {
   //      return false;
   //  }

   for (i = 0; i < str1.Length; i++)
   {
      if (str1.TabWord[i] != str2[i])
      {
         return false;
      }
   }

   return true;
}

boolean WordIsInt(Word kata){
   int i;
   boolean check=false;
   for (i=0; i<kata.Length; i++){
      if (kata.TabWord[i]>=48&&kata.TabWord[i]<=57){
         check = true;
      }
   }
   return check;
}

Word MergeWord(Word kata1, Word kata2){
   int i;
   Word result={"",0};
   result=kata1;
   result.Length += kata2.Length+1;
   result.TabWord[kata1.Length] = BLANK;
   for (i=0;i<kata2.Length;i++){
      result.TabWord[kata1.Length+1+i]=kata2.TabWord[i];
   }
   return result;
}

// char WordToStr(Word kata){
//    int i;
//    char result[NMax];
//    for (i = 0; i<kata.Length;i++){
//       result[i] = kata.TabWord[i];
//    }
//    result[i] = '\0';
//    return result;
// }

void PrintWord(Word kata){
   int i;
   for (i=0;i<kata.Length;i++){
      printf("%c", kata.TabWord[i]);
   }
}