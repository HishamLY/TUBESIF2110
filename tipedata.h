#ifndef _TIPEDATA_h
#define _TIPEDATA_h

#include "point.h"
#include "queue.h"

#define MAX_MAP 10
#define MAX_MAP_BRS 100
#define MAX_MAP_KOL 100
#define MAX_PAIR 10
#define MAPLOC(X,N,I,J) (X).M[N].MM[I][J]
#define BRS(X,N) (X).M[N].Brs
#define KOL(X,N) (X).M[N].Kol

#define PAIR_LEN(P) (P).Len
#define SRC(P) (P).Asal
#define CHR_PAIR (P) (P).chr
#define CHR_PAIR_I(P,i) (P).Pr[i].chr
#define MAP_I_Asal(P,i) SRC_I(P,i).map
#define MAP_I_Tujuan(P,i) DEST_I(P,i).map
#define SRC_I(P,i) (P).Pr[i].Asal
#define DEST_I(P,i) (P).Pr[i].Tujuan
#define DEST(P) (P).Tujuan

#define Que_i(AQ,i) (AQ).Q[i] //Mengakses Queue ke i dari array of Queue

typedef struct {
	int nQueue;
	Queue Q[100];
}ArQ;

typedef struct
{
	POINT Asal,Tujuan;
	char chr;
}Pair;

typedef struct 
{
	int Len;
	Pair Pr[MAX_PAIR];
}TabPair;

typedef struct
{
	int Kol,Brs;
	char MM[MAX_MAP_BRS][MAX_MAP_KOL];
}Map;

typedef struct
{
	int nMap;
	Map M[MAX_MAP];
}Maps;

// Type Data untuk Health
typedef struct 
{
	int HPoint;
	int MaxHPoint;
} Health;

//Type Data untuk EXP
typedef struct 
{
	int EXPoint;
	int MaxEXPoint;
} Experience;

// Type Data Construct Player
typedef struct 
{
	char Name[25];
	int Level;
	Health HP;
	int STR;
	int DEF;
	Experience EXP;
	POINT P;
} Player;

//Type Data Construct Monster
typedef struct 
{
	char Name[25];
	int Level;
	Health HP;
	int STR;
	int DEF;
	Experience EXP;
	int FlagBoss;
	POINT P;
} Monster;

/* Setter dan Getter untuk ADT Karakter */
#define PPOS(X) (X).P
#define PPOS_X(X) (X).P.X
#define PPOS_Y(X) (X).P.Y
#define PPOS_N(X) (X).P.map
#define Name(C) (C).Name
#define Level(C) (C).Level
#define HP(C) (C).HP.HPoint
#define MaxHP(C) (C).HP.MaxHPoint
#define STR(C) (C).STR
#define DEF(C) (C).DEF
#define EXP(C) (C).EXP.EXPoint
#define MaxEXP(C) (C).EXP.MaxEXPoint
#define Boss(C) (C).FlagBoss
#define Point(C) (C).P

int SearchPairId (TabPair TP,char C);
/* Search id SRC dari TabPair, apabila ketemu >=0 indeksnya, jika tidak -1 */

Pair MakePair(POINT P1,POINT P2);
/* Menghasilkan Pair dengan P1 menjadi SRC, dan P2 menjadi DEST */

void CreateEmpty_Map(Maps *M);
/* Membuat Map kosong dengan banyaknya nmap,kolom & baris = 0 */ 
/* I.S. : Sembarang */
/* F.S. : Map memiliki banyaknya nmap, Kolom & Baris = 0 */

#endif