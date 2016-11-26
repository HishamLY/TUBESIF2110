/*
NIM				: 13515120
Nama			: Azis Adi Kuncoro
Tanggal			: 27 September 2016
Topik praktikum : Stack
Deskripsi		: Pra - Praktikum dengan ADT Stack
*/
#include "stackQ.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptySQ (StackQ *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
{
	Top(*S)=0;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptySQ (StackQ S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
	return(Top(S)==0);
}
boolean IsFullSQ (StackQ S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
	return(Top(S)==MaxEl_SQ);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushSQ (StackQ * S, infotype_SQ X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
	Top(*S)++;
	InfoTop(*S)=X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void PopSQ (StackQ * S, infotype_SQ* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
	*X=InfoTop(*S);
	Top(*S)--;
}
