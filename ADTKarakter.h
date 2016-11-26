//	Nama File 	: ADTKarakter.h
/*	Nama/NIM	: Hisham Lazuardi Yusuf/13515069

*/

/* Representasi dari ADT Karakter yang digunakan untuk type Player dan Monster */

#ifndef ADTKarakter_H
#define ADTKarakter_H

//#include "boolean.h"
#include "point.h"
#include "mesinkata.h"
#include "tipedata.h"
#include "Skilltree.h"
#include "bintree.h"

/*  Kamus Umum */
#define IdxMax 100
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999 
/* Indeks tak terdefinisi*/



/* Definisi Koleksi Objek Player */
typedef int IdxType;  /* type indeks */
typedef struct { 
	Player TI[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
	int Neff; /* >=0, banyaknya elemen efektif */
} TabKarakter;

/* Setter dan Getter untuk TabKarakter */
#define Neff(T)   (T).Neff
#define TI(T)     (T).TI
#define Elmt(T,i) (T).TI[(i)]

/* Definisi Koleksi Objek Monster */
typedef int addrStack;
typedef struct { 
	Monster T[20]; /* tabel penyimpan elemen */
	addrStack TOP;  /* alamat TOP: elemen puncak */
} StackM;

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* Creator Player dan Monster */
void CreatePlayer (Player *P1, char *Name);
/* I.S. Sembarang */
/* F.S. Terbentuk type Player yang memiliki 6 atribut */

void CreateMonster (Monster *E, char *Name, int level, int boss);
/* I.S. Sembarang */
/* F.S. Terbentuk suatu type Monster, jika nilai boss == 1 maka akan membentuk boss,
jika boss == 0 maka hanya terbentuk monster biasa */

/* Level Up Player */
void LevelUp (Player *P1,BinTree *ST);
/* I.S. Level player X */
/* F.S. Level player akan bertambah dan atribut yang dimiliki player akan meningkat sesuai dengan level */

void Heal(Player *P1);
/* I.S. Health Point Player sembarang */
/* F.S. Health Point Player bertambah sebanyak 20 */

void SavePlayer (TabKarakter P, char * NamaFile);
/* I.S. TabKarakter terdefinisi dan NamaFile telah terdefinisi
   F.S. Isi dari TabKarakter telah dimasukkan ke dalam File Eksternal dengan nama NamaFile */

int CharToInt (char s);
/* Fungsi konversi dari char ke integer */

void LoadPlayer (TabKarakter * P,char * NamaFile);
/* I.S File Eksternal dengan nama NamaFile terdefinisi
   F.S isi dari File Eksternal telah ditampung di dalam TabKarakter */

void LoadEnemy (StackM * Enemy, char * NamaFile);
/* I.S.
   F.S.	*/

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyS (StackM *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyS (StackM S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullS (StackM S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (StackM * S, Monster X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (StackM * S, Monster * X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void LoadAksiEnemy (ArQ * QT);
/*	I.S.
	F.S. */


#endif