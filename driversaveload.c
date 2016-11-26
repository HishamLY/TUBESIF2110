
#include <stdio.h>
#include "ADTKarakter.h"


int main ()
{
	TabKarakter TP;
	Player P;
	Neff(TP) = 0;
	int i,j,T;
	char nama [25];
	StackM SE;
	CreateEmptyS(&SE);
	Monster M;
	FILE * fileout;
	
	/*scanf("%d",&T);
	for (i=1;i<=T;i++)
	{
		scanf(" %s", nama);
		CreatePlayer(&P,nama);
		printf("Karakter dengan nama ");
		printf("%s", nama);
		printf(" berhasil dibuat");
		printf("\n");
		j = (Neff(TP)+IdxMin);
		Elmt(TP,j) = P;
		Neff(TP)++;
	}
	SavePlayer(TP,"FileEksternal/FileKarakter.txt");
	LoadPlayer(&TP,"FileEksternal/FileKarakter.txt");
	for (i=IdxMin;i<=(Neff(TP)-IdxMin+1);i++)
	{
		printf("%s\n", Name(Elmt(TP,i)));
		printf("%d\n", Level(Elmt(TP,i)));
		printf("%d\n", HP(Elmt(TP,i)));
		printf("%d\n", MaxHP(Elmt(TP,i)));
		printf("%d\n", STR(Elmt(TP,i)));
		printf("%d\n", DEF(Elmt(TP,i)));
		printf("%d\n", EXP(Elmt(TP,i)));
		printf("%d\n", MaxEXP(Elmt(TP,i)));
	}*/
	//Tulis File Eksternal Enemy
	/*fileout = fopen("FileEksternal/Enemy.txt","w");
	
	fprintf(fileout, "%s", "Troll"); fprintf(fileout, "\n");
	fprintf(fileout, "%d", 4); fprintf(fileout, "\n"); 
	fprintf(fileout, "%d", 0); fprintf(fileout, "\n");
	fprintf(fileout, "%s", "Orc"); fprintf(fileout, "\n");
	fprintf(fileout, "%d", 3); fprintf(fileout, "\n"); 
	fprintf(fileout, "%d", 0); fprintf(fileout, "\n");
	fprintf(fileout, "%s", "Goblin"); fprintf(fileout, "\n");
	fprintf(fileout, "%d", 2); fprintf(fileout, "\n"); 
	fprintf(fileout, "%d", 0); fprintf(fileout, "\n");
	fprintf(fileout, "%s", "Reaper"); fprintf(fileout, "\n");
	fprintf(fileout, "%d", 1); fprintf(fileout, "\n"); 
	fprintf(fileout, "%d", 0); fprintf(fileout, "\n");
	fprintf(fileout, ".");
	fclose(fileout);

	//Baca File Eksternal Enemy
	LoadEnemy(&SE,"FileEksternal/Enemy.txt");
	while(!IsEmptyS(SE))
	{
		Pop(&SE, &M);
		printf("%s\n", Name(M));
		printf("%d\n", Level(M));
		printf("%d\n", HP(M));
		printf("%d\n", EXP(M));
		printf("%d\n", STR(M));
	}*/

	/*fileout = fopen("FileEksternal/DataAksi.txt", "w");

	fprintf(fileout,"%s", "ABFAAFAABABFABBFAAABABFAFBFAAABBFABAFABB");
	fprintf(fileout,".\n");
	*/char s[41];
	LoadAksiEnemy(s,"FileEksternal/DataAksi.txt");
	int k = 0;
	while (k<StrLen(s))
	{
		printf("%c", s[k]);
		k++;
		if (k%4==0)
		{
			printf("\n");
		}
	}

	return 0;
}