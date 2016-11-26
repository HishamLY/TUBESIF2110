// Nama File : mainmenu.h

#include "ADTKarakter.h"
#include "mesinkata.h"

#ifndef mainmenu_H
#define mainmenu_H

// Definisi dari clear
#define clear() printf("\033[H\033[J")

// Definisi dari penggunaan warna
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

#define Nil NULL

// Fungsi dan Prosedur

IdxType SearchName (TabKarakter T, char *X);
/* Search apakah ada elemen tabel T yang memiliki sub elemen Name X */
/* Jika ada, menghasilkan indeks i terkecil, dengan Name elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */

void MakeEmpty (TabKarakter * T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

void NewGame (TabKarakter * T, Player *P);
/* Prosedur akan meminta input nama karakter, jika nama karakter belum ada dalam TabKarakter, maka data player akan dibuat.
   Prosedur akan terus meminta input karakter hingga berhasil membuat data player. */

void InterfaceAwal();
/* I.S Tampilan terminal kosong
   F.S Terbentuk tampilan seperti isi pada program */

void Credit();
/* I.S. Tampilan terminal masih dalam mode Menang
   F.S. Terbentuk tampilan Credit pada terminal */

void GameOver();
/* I.S Tampilan terminal kosong
   F.S Terbentuk tampilan seperti isi pada program */
#endif
