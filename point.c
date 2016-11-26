
#define PI 3.14159265
#include "point.h"
#include <stdio.h>

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y,int Z)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
    POINT P;
    Absis(P)=X;
    Ordinat(P)=Y;
    P.map=Z;
    return(P);
}

boolean EQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
    return((Absis(P1)==Absis(P2))&&(Ordinat(P1)==Ordinat(P2))&&(P1.map==P2.map));
}

