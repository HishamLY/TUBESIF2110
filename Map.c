//File : Maptest.c
//Mencoba mekanisme pembacaan map dari file eksternal dan random map

#include "Map.h"


void RandomMap (Map *M)
/*	I.S.
	F.S.	*/
{
	int Row, Col;
	int i,j;
	int A;
	int r;
	int r1,r2;

	(*M).Kol = 20;
	(*M).Brs = 20;

	for (i=0;i<=((*M).Brs-1);i++)
	{
		for(j=0;j<=((*M).Kol-1);j++)
		{
			(*M).MM[i][j] = '#';
		}
	}

	Row = (*M).Brs;
	Col = (*M).Kol;

	do {
		r1 = rand() % Row;
		r2 = rand() % Col;
	} while (r1<=1||r2<=1||r1>=(Row-2)||r2>=(Col-2));

	A = Row * Col;
	// Generate Random Map
	for (i=1;i<=A;i++)
	{
	   InitRand :
		r = rand() % 4;
		if (r==0)
		{
			if ((r1+1)>=(Row-2))
			{
				goto InitRand;
			} else
			{
				(*M).MM[r1+1][r2] = ' ';
				r1++;
			}
		} else if (r==1)
		{
			if ((r2+1)>=(Col-2))
			{
				goto InitRand;
			} else
			{
				(*M).MM[r1][r2+1] = ' ';
				r2++;
			}
		} else if (r==2)
		{
			if ((r1-1)<=1)
			{
				goto InitRand;
			} else
			{
				(*M).MM[r1-1][r2] = ' ';
				r1--;
			}
		} else if (r==3)
		{
			if ((r2-1)<=1)
			{
				goto InitRand;
			} else
			{
				(*M).MM[r1][r2-1] = ' ';
				r2--;
			}
		}
	}

	r = rand() % 2;
	if (r==0)
	{
		j = 1;
		while (j<=2)
		{
			r1 = rand() % Row;
			r2 = rand() % Col;
			if ((*M).MM[r1][r2]==' ')
			{
				(*M).MM[r1][r2] = 'E';
				j++;
			}
		}
	} else
	{
		j = 1;
		while (j<=3)
		{
			r1 = rand() % Row;
			r2 = rand() % Col;
			if ((*M).MM[r1][r2]==' ')
			{
				(*M).MM[r1][r2] = 'E';
				j++;
			}
		}
	}

	j = 1;
	while (j<=2)
	{
		r1 = rand() % Row;
		r2 = rand() % Col;
		if ((*M).MM[r1][r2]==' ')
		{
			(*M).MM[r1][r2] = 'M';
			j++;
		}
	}
}

void CreateLinkSource (Maps * MS, int N)
/*	I.S.
	F.S. */
{
	boolean found;
	int i,j,k,l;

	(*MS).nMap = N;

	found = false;
	i = 17;
	while (i>=0&&!found)
	{
		j = 0;
		while (j<=19&&!found)
		{
			if ((*MS).M[0].MM[j][i]==' ')
			{
				found = true;
				for (l=i;l<=19;l++)
				{
					if (l<19)
					{
						(*MS).M[0].MM[j][l] = ' ';
					} else if (l==19)
					{
						(*MS).M[0].MM[j][l] = '0';
					}
				}
			}
			j++;	
		}
		i--;
	}

	found = false;
	i = 17;
	while (i>=0&&!found)
	{
		j = 0;
		while (j<=19&&!found)
		{
			if ((*MS).M[1].MM[j][i]==' ')
			{
				found = true;
				for (l=i;l<=19;l++)
				{
					if (l<19)
					{
						(*MS).M[1].MM[j][l] = ' ';
					} else if (l==19)
					{
						(*MS).M[1].MM[j][l] = '1';
					}
				}
			}
			j++;	
		}
		i--;
	}

	found = false;
	i = 17;
	while (i>=0&&!found)
	{
		j = 0;
		while (j<=19&&!found)
		{
			if ((*MS).M[2].MM[j][i]==' ')
			{
				found = true;
				for (l=i;l<=19;l++)
				{
					if (l<19)
					{
						(*MS).M[2].MM[j][l] = ' ';
					} else if (l==19)
					{
						(*MS).M[2].MM[j][l] = '2';
					}
				}
			}
			j++;	
		}
		i--;
	}

	found = false;
	i = 17;
	while (i>=0&&!found)
	{
		j = 0;
		while (j<=19&&!found)
		{
			if ((*MS).M[2].MM[i][j]==' ')
			{
				found = true;
				for (l=i;l<=19;l++)
				{
					if (l<19)
					{
						(*MS).M[2].MM[l][j] = ' ';
					} else if (l==19)
					{
						(*MS).M[2].MM[l][j] = '3';
					}
				}
			}
			j++;	
		}
		i--;
	}

	found = false;
	i = 17;
	while (i>=0&&!found)
	{
		j = 0;
		while (j<=19&&!found)
		{
			if ((*MS).M[3].MM[j][i]==' ')
			{
				found = true;
				for (l=i;l<=19;l++)
				{
					if (l<19)
					{
						(*MS).M[3].MM[j][l] = ' ';
					} else if (l==19)
					{
						(*MS).M[3].MM[j][l] = '4';
					}
				}
			}
			j++;	
		}
		i--;
	}

	found = false;
	i = 17;
	while (i>=0&&!found)
	{
		j = 0;
		while (j<=19&&!found)
		{
			if ((*MS).M[3].MM[i][j]==' ')
			{
				found = true;
				for (l=i;l<=19;l++)
				{
					if (l<19)
					{
						(*MS).M[3].MM[l][j] = ' ';
					} else
					{
						(*MS).M[3].MM[l][j] = '5';
					}
				}
			}
			j++;	
		}
		i--;
	}


	found = false;
	i = 17;
	while (i>=0&&!found)
	{
		j = 0;
		while (j<=19&&!found)
		{
			if ((*MS).M[4].MM[j][i]==' ')
			{
				found = true;
				for (l=i;l<=19;l++)
				{
					if (l<19)
					{
						(*MS).M[4].MM[j][l] = ' ';
					} else
					{
						(*MS).M[4].MM[j][l] = '6';
					}
				}
			}
			j++;	
		}
		i--;
	}

}


void CreateLinkDest (Maps * MS, int N)
/*	I.S.
	F.S. */
{
	boolean found;
	int i,j,k,l;

	(*MS).nMap = N;

	found = false;
	i = 2;
	while (i<=19&&!found)
	{
		j = 0;
		while (j<=19&&!found)
		{
			if ((*MS).M[1].MM[j][i]==' ')
			{
				found = true;
				for (l=i;l>=0;l--)
				{
					if (l>0)
					{
						(*MS).M[1].MM[j][l] = ' ';
					} else if (l==0)
					{
						(*MS).M[1].MM[j][l] = '0';
					}
				}
			}
			j++;	
		}
		i++;
	}

	found = false;
	i = 2;
	while (i<=19&&!found)
	{
		j = 0;
		while (j<=19&&!found)
		{
			if ((*MS).M[2].MM[j][i]==' ')
			{
				found = true;
				for (l=i;l>=0;l--)
				{
					if (l>0)
					{
						(*MS).M[2].MM[j][l] = ' ';
					} else if (l==0)
					{
						(*MS).M[2].MM[j][l] = '1';
					}
				}
			}
			j++;	
		}
		i++;
	}

	found = false;
	i = 2;
	while (i<=19&&!found)
	{
		j = 0;
		while (j<=19&&!found)
		{
			if ((*MS).M[3].MM[j][i]==' ')
			{
				found = true;
				for (l=i;l>=0;l--)
				{
					if (l>0)
					{
						(*MS).M[3].MM[j][l] = ' ';
					} else if (l==0)
					{
						(*MS).M[3].MM[j][l] = '2';
					}
				}
			}
			j++;	
		}
		i++;
	}

	found = false;
	i = 2;
	while (i>=0&&!found)
	{
		j = 0;
		while (j<=19&&!found)
		{
			if ((*MS).M[4].MM[j][i]==' ')
			{
				found = true;
				for (l=i;l>=0;l--)
				{
					if (l>0)
					{
						(*MS).M[4].MM[j][l] = ' ';
					} else
					{
						(*MS).M[4].MM[j][l] = '4';
					}
				}
			}
			j++;	
		}
		i++;
	}

	found = false;
	i = 2;
	while (i<=19&&!found)
	{
		j = 0;
		while (j<=19&&!found)
		{
			if ((*MS).M[4].MM[i][j]==' ')
			{
				found = true;
				for (l=i;l>=0;l--)
				{
					if (l>0)
					{
						(*MS).M[4].MM[l][j] = ' ';
					} else
					{
						(*MS).M[4].MM[l][j] = '3';
					}
				}
			}
			j++;	
		}
		i++;
	}

	found = false;
	i = 2;
	while (i<=19&&!found)
	{
		j = 0;
		while (j<=19&&!found)
		{
			if ((*MS).M[5].MM[i][j]==' ')
			{
				found = true;
				for (l=i;l>=0;l--)
				{
					if (l>0)
					{
						(*MS).M[5].MM[l][j] = ' ';
					} else
					{
						(*MS).M[5].MM[l][j] = '5';
					}
				}
			}
			j++;	
		}
		i++;
	}

	found = false;
	i = 2;
	while (i<=19&&!found)
	{
		j = 0;
		while (j<=19&&!found)
		{
			if ((*MS).M[5].MM[j][i]==' ')
			{
				found = true;
				for (l=i;l>=0;l--)
				{
					if (l>0)
					{
						(*MS).M[5].MM[j][l] = ' ';
					} else
					{
						(*MS).M[5].MM[j][l] = '6';
					}
				}
			}
			j++;	
		}
		i++;
	}
	
}


void CreateMap(Maps * MapJelajah)
/*	I.S.
	F.S. */
{
	//Variabel
	int idx;

	CreateEmpty_Map(MapJelajah);
	(*MapJelajah).nMap = 6;
	int A;
	int r,r1,r2;
	int s1,s2;
	int i,j,k,l;
	int count;
	int M,N;
	boolean found;

	//Algroritma
	M = 20;
	N = 30;

	srand(time(NULL));
		
	RandomMap(&(*MapJelajah).M[0]);
	RandomMap(&(*MapJelajah).M[1]);
	RandomMap(&(*MapJelajah).M[2]);
	RandomMap(&(*MapJelajah).M[3]);
	RandomMap(&(*MapJelajah).M[4]);
	RandomMap(&(*MapJelajah).M[5]);

	found = false;
	i = 2;
	while (i<=19&&!found)
	{
		j = 0;
		while (j<=19&&!found)
		{
			if ((*MapJelajah).M[1].MM[j][i]==' ')
			{
				found = true;
				(*MapJelajah).M[0].MM[j][i] = 'P';
			}
			j++;	
		}
		i++;
	}

	do {
		s1 = rand() % M;
		s2 = rand() % N;
	} while ((*MapJelajah).M[5].MM[s1][s2]!=' ');
	(*MapJelajah).M[5].MM[s1][s2] = 'B';

	CreateLinkSource(MapJelajah, 6);
	CreateLinkDest(MapJelajah, 6);	

	FILE * fileout;
	fileout = fopen("FileEksternal/FileMap.txt","w");
	for (i=0;i<=5;i++)
	{
		for (j=0;j<=19;j++)
		{
			for (k=0;k<=19;k++)
			{
				fprintf(fileout, "%c", (*MapJelajah).M[i].MM[j][k]);
			}
			if (j!=19)
			{
				fprintf(fileout,"\n");
			} else
			{
				if (i!=5)
				{
					fprintf(fileout,",\n");	
				} else
				{
					fprintf(fileout, ".\n");
				}
				
			}
		}
	}
	fclose(fileout);
}
