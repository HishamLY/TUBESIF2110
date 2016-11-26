//File : Maptest.c
//Mencoba mekanisme pembacaan map dari file eksternal dan random map

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void RandomMap (Map *M)
/*	I.S.
	F.S.	*/
{
	for (i=0;i<=((*M).Brs-1);i++)
	{
		for(j=0;j<=((*M).Kol-1);j++)
		{
			(*M).MM[i][j] = '#';
		}
	}
	for (i=0;i<=((*M).Brs-1);i++)
	{
		for(j=0;j<=((*M).Kol-1);j++)
		{
			(*M).MM[i][j] = '#';
		}
	}
}

int main ()
{
	//Variabel
	int idx;
	char Map[30][30], Map2[30][30], Map3[30][30], Map4[30][30], Map5[30][30], Map6[30][30];
	Map Map7; Map7.Brs=30; Map7.Kol=30;
	int A;
	int r,r1,r2;
	int s1, s2;
	int i,j,k;
	int XStart,YStart;
	int count;

	//Algroritma
	M = 15;
	N = 20;

	srand (time(NULL));
	//srand (time(NULL));
	
	RandomMap(Map7);

	// Generate Map
	for (i=0;i<=(M-1);i++)
	{
		for(j=0;j<=(N-1);j++)
		{
			Map[i][j] = '#';
		}
	}
	// Generate Map
	for (i=0;i<=(M-1);i++)
	{
		for(j=0;j<=(N-1);j++)
		{
			Map2[i][j] = '#';
		}
	}
	// Generate Map
	for (i=0;i<=(M-1);i++)
	{
		for(j=0;j<=(N-1);j++)
		{
			Map3[i][j] = '#';
		}
	}
	// Generate Map
	for (i=0;i<=(M-1);i++)
	{
		for(j=0;j<=(N-1);j++)
		{
			Map4[i][j] = '#';
		}
	}
	// Generate Map
	for (i=0;i<=(M-1);i++)
	{
		for(j=0;j<=(N-1);j++)
		{
			Map5[i][j] = '#';
		}
	}
	// Generate Map
	for (i=0;i<=(M-1);i++)
	{
		for(j=0;j<=(N-1);j++)
		{
			Map6[i][j] = '#';
		}
	}



	// Start Point
	do {
		r1 = rand() % M;
		r2 = rand() % N;
	} while (r1<=1||r2<=1||r1>=(M-2)||r2>=(N-2));

	A = M * N;

	// Generate Random Map
		for (i=1;i<=A;i++)
		{
			//printf("bug1\n");
		  InitRand :
			r = rand() % 4;
			if (r==0)
			{
				if ((r1+1)>=(M-2))
				{
					goto InitRand;
				} else
				{
					Map[r1+1][r2] = ' ';
					r1++;
				}
			} else if (r==1)
			{
				if ((r2+1)>=(N-2))
				{
					goto InitRand;
				} else
				{
					Map[r1][r2+1] = ' ';
					r2++;
				}
			} else if (r==2)
			{
				if ((r1-1)<=1)
				{
					goto InitRand;
				} else
				{
					Map[r1-1][r2] = ' ';
					r1--;
				}
			} else if (r==3)
			{
				if ((r2-1)<=1)
				{
					goto InitRand;
				} else
				{
					Map[r1][r2-1] = ' ';
					r2--;
				}
			}
			//printf("bug2\n");
		}

		do {
			s1 = rand() % M;
			s2 = rand() & M;
		} while ((Map[s1][s2]!=' ')||(r1<=1||r2<=1||r1>=(M-2)||r2>=(N-2)));
		Map[s1][s2] = 'P';
	

	for (i=1;i<=A;i++)
		{
		  InitRand2 :
			r = rand() % 4;
			if (r==0)
			{
				if ((r1+1)>=(M-2))
				{
					goto InitRand2;
				} else
				{
					Map2[r1+1][r2] = ' ';
					r1++;
				}
			} else if (r==1)
			{
				if ((r2+1)>=(N-2))
				{
					goto InitRand2;
				} else
				{
					Map2[r1][r2+1] = ' ';
					r2++;
				}
			} else if (r==2)
			{
				if ((r1-1)<=1)
				{
					goto InitRand2;
				} else
				{
					Map2[r1-1][r2] = ' ';
					r1--;
				}
			} else if (r==3)
			{
				if ((r2-1)<=1)
				{
					goto InitRand2;
				} else
				{
					Map2[r1][r2-1] = ' ';
					r2--;
				}
			}
		}



for (i=1;i<=A;i++)
		{
		  InitRand3 :
			r = rand() % 4;
			if (r==0)
			{
				if ((r1+1)>=(M-2))
				{
					goto InitRand3;
				} else
				{
					Map3[r1+1][r2] = ' ';
					r1++;
				}
			} else if (r==1)
			{
				if ((r2+1)>=(N-2))
				{
					goto InitRand3;
				} else
				{
					Map3[r1][r2+1] = ' ';
					r2++;
				}
			} else if (r==2)
			{
				if ((r1-1)<=1)
				{
					goto InitRand3;
				} else
				{
					Map3[r1-1][r2] = ' ';
					r1--;
				}
			} else if (r==3)
			{
				if ((r2-1)<=1)
				{
					goto InitRand3;
				} else
				{
					Map3[r1][r2-1] = ' ';
					r2--;
				}
			}
		}


for (i=1;i<=A;i++)
		{
		  InitRand4 :
			r = rand() % 4;
			if (r==0)
			{
				if ((r1+1)>=(M-2))
				{
					goto InitRand4;
				} else
				{
					Map4[r1+1][r2] = ' ';
					r1++;
				}
			} else if (r==1)
			{
				if ((r2+1)>=(N-2))
				{
					goto InitRand4;
				} else
				{
					Map4[r1][r2+1] = ' ';
					r2++;
				}
			} else if (r==2)
			{
				if ((r1-1)<=1)
				{
					goto InitRand4;
				} else
				{
					Map4[r1-1][r2] = ' ';
					r1--;
				}
			} else if (r==3)
			{
				if ((r2-1)<=1)
				{
					goto InitRand4;
				} else
				{
					Map4[r1][r2-1] = ' ';
					r2--;
				}
			}
		}


for (i=1;i<=A;i++)
		{
		  InitRand5 :
			r = rand() % 4;
			if (r==0)
			{
				if ((r1+1)>=(M-2))
				{
					goto InitRand5;
				} else
				{
					Map5[r1+1][r2] = ' ';
					r1++;
				}
			} else if (r==1)
			{
				if ((r2+1)>=(N-2))
				{
					goto InitRand5;
				} else
				{
					Map5[r1][r2+1] = ' ';
					r2++;
				}
			} else if (r==2)
			{
				if ((r1-1)<=1)
				{
					goto InitRand5;
				} else
				{
					Map5[r1-1][r2] = ' ';
					r1--;
				}
			} else if (r==3)
			{
				if ((r2-1)<=1)
				{
					goto InitRand5;
				} else
				{
					Map5[r1][r2-1] = ' ';
					r2--;
				}
			}
		}


for (i=1;i<=A;i++)
		{
		  InitRand6 :
			r = rand() % 4;
			if (r==0)
			{
				if ((r1+1)>=(M-2))
				{
					goto InitRand6;
				} else
				{
					Map6[r1+1][r2] = ' ';
					r1++;
				}
			} else if (r==1)
			{
				if ((r2+1)>=(N-2))
				{
					goto InitRand6;
				} else
				{
					Map6[r1][r2+1] = ' ';
					r2++;
				}
			} else if (r==2)
			{
				if ((r1-1)<=1)
				{
					goto InitRand6;
				} else
				{
					Map6[r1-1][r2] = ' ';
					r1--;
				}
			} else if (r==3)
			{
				if ((r2-1)<=1)
				{
					goto InitRand6;
				} else
				{
					Map6[r1][r2-1] = ' ';
					r2--;
				}
			}
		}




	FILE * fileout;
	fileout = fopen("FileEksternal/FileMap.txt","w");
	for (i=0;i<=(M-1);i++)
	{
		for(j=0;j<=(N-1);j++)
		{

			fprintf(fileout,"%c",Map[i][j]);
		}
		if (i==M-1)
		{
			fprintf(fileout,",\n");
		} else
		{
			fprintf(fileout, "\n");
		}
	}

	for (i=0;i<=(M-1);i++)
	{
		for(j=0;j<=(N-1);j++)
		{

			fprintf(fileout,"%c",Map2[i][j]);
		}
		if (i==M-1)
		{
			fprintf(fileout,",\n");
		} else
		{
			fprintf(fileout, "\n");
		}
	}

	for (i=0;i<=(M-1);i++)
	{
		for(j=0;j<=(N-1);j++)
		{

			fprintf(fileout,"%c",Map3[i][j]);
		}
		if (i==M-1)
		{
			fprintf(fileout,",\n");
		} else
		{
			fprintf(fileout, "\n");
		}
	}

	for (i=0;i<=(M-1);i++)
	{
		for(j=0;j<=(N-1);j++)
		{

			fprintf(fileout,"%c",Map4[i][j]);
		}
		if (i==M-1)
		{
			fprintf(fileout,",\n");
		} else
		{
			fprintf(fileout, "\n");
		}
	}

	for (i=0;i<=(M-1);i++)
	{
		for(j=0;j<=(N-1);j++)
		{

			fprintf(fileout,"%c",Map5[i][j]);
		}
		if (i==M-1)
		{
			fprintf(fileout,",\n");
		} else
		{
			fprintf(fileout, "\n");
		}
	}

	for (i=0;i<=(M-1);i++)
	{
		for(j=0;j<=(N-1);j++)
		{

			fprintf(fileout,"%c",Map6[i][j]);
		}
		if (i==M-1)
		{
			fprintf(fileout,".\n");
		} else
		{
			fprintf(fileout, "\n");
		}
	}


	fclose(fileout);
	return 0;
}