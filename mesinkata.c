/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#include "boolean.h"
#include "mesinkata.h"

#define NMax 50
#define BLANK ' '
#define MARK '.'

boolean EndKata;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (CC==BLANK&&CC!=MARK) {
      ADV();
    }
}

void STARTKATA(char * NamaFile)
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    START(NamaFile);
    IgnoreBlank();
    if (CC==MARK) {
      EndKata = true;
    } else {
      EndKata = false;
      SalinKata();
    }
}
void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.     
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    IgnoreBlank();
    if (CC==MARK) {
      EndKata = true;
    } else {
      SalinKata();
    }
    IgnoreBlank();
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
  int i = 1;
  do {
    CKata.TabKata[i] = CC;
    ADV();
    if ((CC!=MARK)&&(CC!=BLANK)) {
       i++;
    } 
  } while (CC!=MARK&&CC!=BLANK);
  if (i>=NMax) {
    CKata.Length = NMax;
  } else {
    CKata.Length = i;
  }
}

int StrLen (char *S)
/* Fungsi untuk menghitung panjang string */
{
  int i;

  i = 0;
  while (S[i]!='\0')
  {
    i++;
  }

  return i;
}

boolean IsKataSama (char *S1, char *S2)
/* Fungsi untuk mengecek apakah kedua kata sama */
{
  int i;

  if (StrLen(S1)==StrLen(S2))
  {
    i = 0;
    while ((i<StrLen(S1)-1)&&S1[i]==S2[i])
    {
      i++;
    }
    if (S1[i]==S2[i])
    {
      return true;
    } else
    {
      return false;
    }
  } else
  {
    return false;
  }
}

void CopyKata (char *S1, char *S2)
/* I.S. S1 terdefinisi, S2 sembarang
   F.S. S2 merupakan salinan dari S1 */
{
  int i;

  i = 0;
  while (i<=StrLen(S1)-1)
  {
    S2[i] = S1[i];
    i++;
  }
  S2[i] = '\0';
}