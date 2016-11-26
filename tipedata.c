#include "tipedata.h"


int SearchPairId (TabPair TP,char C)
/* Search id SRC dari TabPair, apabila ketemu >=0 indeksnya, jika tidak -1 */
{
	for (int i=0;i<PAIR_LEN(TP);i++)
	{
		if (C==CHR_PAIR_I(TP,i))
			return(i);
	}
	return(-1);
}

Pair MakePair(POINT P1,POINT P2)
/* Menghasilkan Pair dengan P1 menjadi SRC, dan P2 menjadi DEST */
{
	Pair Pr;
	SRC(Pr)=P1;
	DEST(Pr)=P2;
	return(Pr);
}


void CreateEmpty_Map(Maps *M)
/* Membuat Map kosong dengan banyaknya nmap = 0 */ 
/* I.S. : Sembarang */
/* F.S. : Map memiliki banyaknya nmap = 0 */
{
	(*M).nMap=0;
}
