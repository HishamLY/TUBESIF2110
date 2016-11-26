/* File: point.h */
/* Tanggal: 28 Agustus 2016 */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#ifndef POINT_H
#define POINT_H

#include "boolean.h"
#include <math.h>

typedef struct { 
	int map;
	int X; /* absis   */
	int Y; /* ordinat */
} POINT;

/* *** Notasi Akses: Selektor POINT *** */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y
        
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y,int Z);
/* Membentuk sebuah POINT dari komponen-komponennya */


boolean EQ (POINT P1, POINT P2);
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */

#endif
