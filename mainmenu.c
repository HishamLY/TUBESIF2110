#include <stdio.h>
#include <stdlib.h>
#include "mainmenu.h"
#include "mesinkata.h"

IdxType SearchName (TabKarakter T, char * X)
/* Search apakah ada elemen tabel T yang memiliki sub elemen Name X */
/* Jika ada, menghasilkan indeks i terkecil, dengan Name elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
{
	boolean found;
	int i;
	found = false;
	i = IdxMin;
	while ((i <= Neff(T)) && !found)
	{
		if(IsKataSama(Name(Elmt(T,i)), X))
		{
			found = true;
		} else
		{
			i++;
		}
	}
	if (found)
	{
		return i;
	}
	else
	{
		return IdxUndef;
	}
}

void NewGame (TabKarakter * T, Player *P)
/*
Prosedur akan meminta input nama karakter, jika nama karakter belum ada dalam TabKarakter, maka data player akan dibuat.
Prosedur akan terus meminta input karakter hingga berhasil membuat data player.
*/
{
	char nama[25];
	int i;
	boolean success;
	success=false;
	int j;

	while(success==false)
	{
		printf("Masukkan nama karakter yang dinginkan : (Maks 20 karakter tanpa spasi) ");
		printf("\n> ");
		scanf(" %s", nama);
		i = SearchName(*T, nama);
		if (i == IdxUndef)
		{
			CreatePlayer(P,nama);
			printf("Karakter dengan nama ");
			printf("%s", nama);
			printf(" berhasil dibuat");
			printf("\n");
			success = true;
		}
		else
		{
			printf("Nama tersebut sudah dipakai");
			printf("\n");
		}
	}
}

void InterfaceAwal()
/* I.S Tampilan terminal kosong
   F.S Terbentuk tampilan seperti isi pada program */
{
	//Variabel


	//Algoritma
	clear();

	printf("\n");
	printf("\n");
	printf(COLOR_YELLOW"	✄▒█▀▀█ ▒█▀▀█ ▀█▀ ▒█▀▀█ ▒█░▒█ ▀▀█▀▀ 　 ▒█▀▀▀█ ▒█▀▀▀█ ▒█░▒█ ▒█░░░ ▒█▀▀▀█ \n");
	printf("	✄▒█▀▀▄ ▒█▄▄▀ ▒█░ ▒█░▄▄ ▒█▀▀█ ░▒█░░ 　 ░▀▀▀▄▄ ▒█░░▒█ ▒█░▒█ ▒█░░░ ░▀▀▀▄▄ \n");
	printf("	✄▒█▄▄█ ▒█░▒█ ▄█▄ ▒█▄▄█ ▒█░▒█ ░▒█░░ 　 ▒█▄▄▄█ ▒█▄▄▄█ ░▀▄▄▀ ▒█▄▄█ ▒█▄▄▄█ \n"COLOR_RESET);

	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf(COLOR_BLUE"                             ╔═══════════════════════════╗");printf("\n");
	printf("                             ║                           ║ \n");
	printf("                             ║      1. NEW GAME          ║ \n");
	printf("                             ║                           ║ \n");
	printf("                             ║      2. START GAME        ║\n");
	printf("                             ║                           ║ \n");
	printf("                             ║      3. LOAD GAME         ║ \n");
	printf("                             ║                           ║ \n");
	printf("                             ║      4. EXIT              ║ \n");
	printf("                             ║                           ║\n");
	printf("                             ╚═══════════════════════════╝"COLOR_RESET);printf("\n");
}

void InstructionMain()
/*	I.S.
	F.S. */
{
	printf("\n");
	printf("\n");
	printf("                             ╔══════════════════════════════════════════════╗");printf("\n");
	printf("                             ║                                              ║ \n");
	printf("                             ║ > GU : GO UP         > SKILL : DISPLAY SKILL ║ \n");
	printf("                             ║ > GD : GO DOWN       > SAVE  : SAVE GAME     ║ \n");
	printf("                             ║ > GR : GO RIGHT      > LOAD  : LOAD GAME     ║ \n");
	printf("                             ║ > GL : GO LEFT       > EXIT  : EXIT GAME     ║ \n");
	printf("                             ║                                              ║ \n");
	printf("                             ╚══════════════════════════════════════════════╝"COLOR_RESET);printf("\n");
	printf("\n");
}

void Credit();
/* I.S. Tampilan terminal masih dalam mode Menang
   F.S. Terbentuk tampilan Credit pada terminal */

void GameOver()
{
clear();
printf("\n");
printf("\n");
printf(COLOR_YELLOW"	   _______  _______  _______  _______    _______           _______  _______ \n");
printf("	   (  ____ \\(  ___  )(       )(  ____ \\  (  ___  )|\\     /|(  ____ \\(  ____ ) \n");
printf("	   | (    \\/| (   ) || () () || (    \\/  | (   ) || )   ( || (    \\/| (    )| \n");
printf("	   | |      | (___) || || || || (__      | |   | || |   | || (__    | (____)| \n");
printf("	   | | ____ |  ___  || |(_)| ||  __)     | |   | |( (   ) )|  __)   |     __) \n");
printf("	   | | \\_  )| (   ) || |   | || (        | |   | | \\ \\_/ / | (      | (\\ (    \n");
printf("	   | (___) || )   ( || )   ( || (____/\\  | (___) |  \\   /  | (____/\\| ) \\ \\__ \n");
printf("	   (_______)|/     \\||/     \\|(_______/  (_______)   \\_/   (_______/|/   \\__/ \n"COLOR_RESET);
 }
