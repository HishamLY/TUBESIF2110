// Nama File 	: ADTKarakter.c
// Nama/NIM		: Hisham Lazuardi Yusuf/13515069

#include "ADTKarakter.h"

/* Creator Player dan Monster */
void CreatePlayer (Player *P1, char *Name)
/* F.S. Terbentuk type Player yang memiliki 6 atribut */
{
	CopyKata(Name,Name(*P1));
	Level(*P1) = 1;
	MaxHP(*P1) = 50;
	HP(*P1) = MaxHP(*P1);
	STR(*P1) = 6;
	DEF(*P1) = 5;
	EXP(*P1) = 0;
	MaxEXP(*P1) = 100;
}

void CreateMonster (Monster *E, char *Name, int level, int boss)
/* I.S. Sembarang */
/* F.S. Terbentuk suatu type Monster, jika nilai boss == 1 maka akan membentuk boss,
jika boss == 0 maka hanya terbentuk monster biasa */
{
	if (boss==0)
	{
		CopyKata(Name,Name(*E));
		Level(*E) = level;
		HP(*E) = 30+10*level;
		STR(*E) = 3+2*level;
		DEF(*E) = 3+1*level;
		EXP(*E) = 30+30*level;
		Boss(*E) = boss;
	} else
	{
		CopyKata(Name,Name(*E));
		Level(*E) = level;
		HP(*E) = 300;
		STR(*E) = 50;
		DEF(*E) = 35;
		EXP(*E) = 200;
		Boss(*E) = boss;
	} 
}

void LevelUp (Player *P1,BinTree *ST)
/* I.S. Level player X */
/* F.S. Level player akan bertambah dan atribut yang dimiliki player akan meningkat sesuai dengan level */
{
	//Variabel

	//Algoritma
	if (Level(*P1)<10)
	{
		Level(*P1)++;
		MaxHP(*P1) += (10 + 5*Level(*P1));
		HP(*P1) = MaxHP(*P1);
		STR(*P1) += (3 + 2*Level(*P1));
		DEF(*P1) += (4 + 1*Level(*P1));
		EXP(*P1) = EXP(*P1) % MaxEXP(*P1);
		MaxEXP(*P1) += (10*Level(*P1));
		InterfaceSkill(ST,P1);
	}
}

void Heal(Player *P1)
/* I.S. Health Point Player sembarang */
/* F.S. Health Point Player bertambah sebanyak 20 */
{
	HP(*P1) += 20;
	if (HP(*P1)>MaxHP(*P1))
	{
		HP(*P1) = MaxHP(*P1);
	}
}

void SavePlayer (TabKarakter P, char * NamaFile)
/* I.S. TabKarakter terdefinisi dan NamaFile telah terdefinisi
   F.S. Isi dari TabKarakter telah dimasukkan ke dalam File Eksternal dengan nama NamaFile */
{
	//Kamus
	FILE * fileout;
	int i,j;

	//Algoritma
	fileout = fopen(NamaFile,"w");
	i = IdxMin;
	j = Neff(P) - IdxMin + 1;
	while (i<=j)
	{
		fprintf(fileout, "%s", Name(Elmt(P,i))); fprintf(fileout, "\n");
		fprintf(fileout, "%d", Level(Elmt(P,i))); fprintf(fileout, "\n"); 
		fprintf(fileout, "%d", HP(Elmt(P,i))); fprintf(fileout, "\n");
		fprintf(fileout, "%d", MaxHP(Elmt(P,i))); fprintf(fileout, "\n");
		fprintf(fileout, "%d", STR(Elmt(P,i))); fprintf(fileout, "\n");
		fprintf(fileout, "%d", DEF(Elmt(P,i))); fprintf(fileout, "\n");
		fprintf(fileout, "%d", EXP(Elmt(P,i))); fprintf(fileout, "\n");
		fprintf(fileout, "%d", MaxEXP(Elmt(P,i))); fprintf(fileout, ",\n");
		i++;
	}
	fprintf(fileout, ".");
	fclose(fileout);
}

int CharToInt (char s)
/* Fungsi konversi dari char ke integer */
{
	switch(s)
	{
		case '0' : {return 0; break;}
		case '1' : {return 1; break;}
		case '2' : {return 2; break;}
		case '3' : {return 3; break;}
		case '4' : {return 4; break;}
		case '5' : {return 5; break;}
		case '6' : {return 6; break;}
		case '7' : {return 7; break;}
		case '8' : {return 8; break;}
		case '9' : {return 9; break;}
	}
}

void LoadPlayer (TabKarakter * P,char * NamaFile)
/* I.S File Eksternal dengan nama NamaFile terdefinisi
   F.S isi dari File Eksternal telah ditampung di dalam TabKarakter */
{
	//Kamus
	Neff(*P) = 0;
	FILE * filein;
	int i,j;
	int value;
	char c[25];

	//Algoritma
	START(NamaFile);
	i = 1;
	EOP = false;
	while (!EOP)
	{
		j = 0;
		while (CC!='\n')
		{
			c[j] = CC;
			j++;
			ADV();
		}
		c[j] = '\0';
		CopyKata(c,Name(Elmt(*P,i)));
		ADV();
		value = 0;
		while(CC!='\n')
		{
			value = (value*10) + CharToInt(CC);
			ADV();
		}
		Level(Elmt(*P,i)) = value;
		ADV();
		value = 0;
		while(CC!='\n')
		{
			value = (value*10) + CharToInt(CC);
			ADV();
		}
		HP(Elmt(*P,i)) = value;
		ADV();
		value = 0;
		while(CC!='\n')
		{
			value = (value*10) + CharToInt(CC);
			ADV();
		}
		MaxHP(Elmt(*P,i)) = value;
		ADV();
		value = 0;
		while(CC!='\n')
		{
			value = (value*10) + CharToInt(CC);
			ADV();
		}
		STR(Elmt(*P,i)) = value;
		ADV();
		value = 0;
		while(CC!='\n')
		{
			value = (value*10) + CharToInt(CC);
			ADV();
		}
		DEF(Elmt(*P,i)) = value;
		ADV();
		value = 0;
		while(CC!='\n')
		{
			value = (value*10) + CharToInt(CC);
			ADV();
		}
		EXP(Elmt(*P,i)) = value;
		ADV();
		value = 0;
		while(CC!=',')
		{
			value = (value*10) + CharToInt(CC);
			ADV();
		}
		MaxEXP(Elmt(*P,i)) = value;
		ADV();
		ADV();
		i++;
	}
	Neff(*P) = i-1;
}

void LoadEnemy (StackM * Enemy, char * NamaFile)
/* I.S.
   F.S.	*/
{
	//Kamus
	CreateEmptyS(Enemy);
	Monster M;
	int i,j;
	int value;
	char name[25];
	int Level, FlagBoss;


	//Algoritma
	START(NamaFile);
	EOP = false;
	while (!EOP)
	{
		i = 0;
		while (CC!='\n')
		{
			name[i] = CC;
			i++;
			ADV();
		}
		name[i] = '\0';
		ADV();
		value = 0;
		while (CC!='\n')
		{
			value = (value*10) + CharToInt(CC);
			ADV();
		}
		Level = value;
		ADV();
		FlagBoss = CharToInt(CC);
		ADV();
		ADV();
		CreateMonster(&M, name, Level, FlagBoss);
		Push(Enemy, M);
	}
}

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyS (StackM * S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
{
	Top(*S)=0;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyS (StackM S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
	return(Top(S)==0);
}
boolean IsFullS (StackM S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
	return(Top(S)==19);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (StackM * S, Monster X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
	Top(*S)++;
	InfoTop(*S)=X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (StackM * S, Monster * X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
	*X=InfoTop(*S);
	Top(*S)--;
}

void LoadAksiEnemy (ArQ * QT)
/*	I.S.
	F.S. */
{	
	int n=0;
	int cnt=0;
	START("FileEksternal/DataAksi.txt");
	while(!EOP)
	{
		//printf("%c",CC);
		CreateEmpty(&Que_i(*QT,n),4);
		cnt=0;
		while(cnt<=3)
		{				
				Add(&Que_i(*QT,n),CC);
				ADV();
				cnt++;
		}
		n++;
	}
	(*QT).nQueue=n;
}
