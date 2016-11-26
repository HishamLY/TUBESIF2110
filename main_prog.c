#include "mesinkar.h"
#include "tipedata.h"
#include "boolean.h"
#include "point.h"
#include "ADTKarakter.h"
#include "mesinkata.h"
#include "Skilltree.h"
#include "battle.h"
#include <stdio.h>
#include <stdlib.h>


#define PAGARLOGO '#'
#define PATHLOGO ' '	
#define MAPCHANGESYMBOL ','
#define PLAYERLOGO 'P'	
void clrscr()
{
    system("@cls||clear");
}
void movequeue(Queue *Q)
{
    //Queue Q;
    // CreateEmpty(Q,40);
    Add(Q,'F');
    Add(Q,'A');
    Add(Q,'B');
    Add(Q,'A');
    Add(Q,'A');
    Add(Q,'A');
    Add(Q,'F');
    Add(Q,'B');
    Add(Q,'B');
    Add(Q,'F');
    Add(Q,'B');
    Add(Q,'A');
    Add(Q,'B');
    Add(Q,'F');
    Add(Q,'A');
    Add(Q,'A');
    Add(Q,'F');
    Add(Q,'B');
    Add(Q,'F');
    Add(Q,'A');
    Add(Q,'A');
    Add(Q,'A');
    Add(Q,'F');
    Add(Q,'A');
    Add(Q,'A');
    Add(Q,'A');
    Add(Q,'F');
    Add(Q,'A');
    Add(Q,'A');
    Add(Q,'A');
    Add(Q,'B');
    Add(Q,'A');
    Add(Q,'B');
    Add(Q,'A');
    Add(Q,'A');
    Add(Q,'B');
    Add(Q,'F');
    Add(Q,'B');
    Add(Q,'B');
    Add(Q,'A');
}

boolean WinFlag=false;
char MSG[1000];
void Load_Map(Maps *M,Player *P,TabPair *TP)
{
	int n,i,j;
	n=i=j=0;
	
	START("FileEksternal/FileMap.txt");
	//printf("%d\n",(int)CC-(int)'0');
	
	while (!EOP)
	{
		
		if (CC==PLAYERLOGO)//Special Case
		{
			PPOS(*P).map=n;
			PPOS(*P).X=j;
			PPOS(*P).Y=i;
		}
		if (('0'<=CC)&&(CC<='9'))
		{
			
			POINT P=MakePOINT(j,i,n);
			int id=SearchPairId(*TP,CC);
			printf("kode %c : %d %d - %d\n",CC,j,i,id);
			if (id<0)
			{
				POINT PNIL=MakePOINT(0,0,n);
				(*TP).Pr[PAIR_LEN(*TP)]=MakePair(P,PNIL);
				CHR_PAIR_I(*TP,PAIR_LEN(*TP))=CC;
				PAIR_LEN(*TP)++;
			}
			else {				
				DEST_I((*TP),id)=MakePOINT(P.X,P.Y,n);
			}
		}

		if (CC==MAPCHANGESYMBOL)
		{
			
			BRS((*M),n)=i+1;
			KOL((*M),n)=j;
			ADV();
			ADV();
			n++;
			i=0;
			j=0;
		}
		else if (CC=='\n') /* Read vertical */
		{
			j=0; i++;
		}
		else{  /* Read horizontal */
			MAPLOC((*M),n,i,j)=CC; j++;
		}


		ADV();
	}

	BRS((*M),n)=i+1;
	KOL((*M),n)=j;
	(*M).nMap=n+1;
	
	
}

void TulisMap(Maps M,Player P)
{
	//printf("PLAYER %d %d %d\n",PPOS_N(P),PPOS_X(P),PPOS_Y(P));
	//printf("NMAP = %d\n",M.nMap);
	//printf("=%c=\n",MAPLOC(M,PPOS_N(P),PPOS_Y(P),PPOS_X(P)+1));
	int n=PPOS(P).map;
		//printf("%d %d\n",BRS(M,n),KOL(M,n));
	for (int i=0;i<BRS(M,n);i++)
		for (int j=0;j<KOL(M,n);j++)
		{
			
			if (('0'<=MAPLOC(M,n,i,j))&&(MAPLOC(M,n,i,j)<='9'))
				printf("%c",PATHLOGO); 
			else
				printf("%c",MAPLOC(M,n,i,j));
			
			
			if (j==KOL(M,n)-1)
				printf("\n");
		}
	
}

void Mode_Jelajah(Maps *M,Player *P,TabPair *TP,BinTree *ST)
{
	//clrscr();
	char A,B;
	char S[100];
	printf("\n| %s | LVL : %d | HP : %d/%d | STR : %d | DEF : %d | EXP : %d |\n",Name(*P),Level(*P),HP(*P),MaxHP(*P),STR(*P),DEF(*P),EXP(*P));
	//printf("PLAYER : %d - %d %d\n",PPOS(*P).map,PPOS(*P).X,PPOS(*P).Y);

	TulisMap(*M,*P);
	printf("%s\n",MSG); CopyKata(" ",MSG);
	printf("COMMAND : "); scanf("%s",S);
	
	if (IsKataSama(S,"GU"))
	{
		POINT PDest=MakePOINT(PPOS(*P).X,PPOS(*P).Y-1,PPOS(*P).map);
		char chr_dest=MAPLOC((*M),PPOS(*P).map,PDest.Y,PDest.X);
		
		if ((PDest.Y>=0)&&(chr_dest!=PAGARLOGO)) //validasi
		{
			if (('0'<=chr_dest)&&(chr_dest<='9')) //Cek portal //Kasus khusus
			{
				if (('0'<=chr_dest)&&(chr_dest<='9')) //Cek portal //Kasus khusus
			{
				int id=SearchPairId(*TP,chr_dest); //pasti ketemu
				if (EQ(SRC_I(*TP,id),PDest)) /*MASIH BINGUNG*/
				{
						MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PATHLOGO;

						if ((DEST_I(*TP,id).Y-1>=0)&&(MAPLOC((*M),DEST_I(*TP,id).map,DEST_I(*TP,id).Y-1,DEST_I(*TP,id).X)!='#'))//Cek atas visibel
						{
							PPOS(*P)=MakePOINT(DEST_I(*TP,id).X,DEST_I(*TP,id).Y-1,DEST_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
						else if((DEST_I(*TP,id).Y+1<=BRS(*M,DEST_I(*TP,id).map))&&(MAPLOC((*M),DEST_I(*TP,id).map,DEST_I(*TP,id).Y+1,SRC_I(*TP,id).X)!='#'))
						{
							PPOS(*P)=MakePOINT(DEST_I(*TP,id).X,DEST_I(*TP,id).Y+1,DEST_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
						else if((DEST_I(*TP,id).X-1>=0)&&(MAPLOC((*M),DEST_I(*TP,id).map,DEST_I(*TP,id).Y,DEST_I(*TP,id).X-1)!='#'))
						{
							PPOS(*P)=MakePOINT(DEST_I(*TP,id).X-1,DEST_I(*TP,id).Y,DEST_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
						else if ((DEST_I(*TP,id).X+1<=KOL(*M,DEST_I(*TP,id).map))&&(MAPLOC((*M),DEST_I(*TP,id).map,DEST_I(*TP,id).Y,SRC_I(*TP,id).X+1)!='#'))
						{
							PPOS(*P)=MakePOINT(DEST_I(*TP,id).X+1,DEST_I(*TP,id).Y,DEST_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
				}
				else if (EQ(DEST_I(*TP,id),PDest))
				{
						MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PATHLOGO;

						if ((SRC_I(*TP,id).Y-1>=0)&&(MAPLOC((*M),SRC_I(*TP,id).map,SRC_I(*TP,id).Y-1,SRC_I(*TP,id).X)!='#'))//Cek atas visibel
						{
							PPOS(*P)=MakePOINT(SRC_I(*TP,id).X,SRC_I(*TP,id).Y-1,SRC_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
						else if((SRC_I(*TP,id).Y+1<=BRS(*M,SRC_I(*TP,id).map))&&(MAPLOC((*M),SRC_I(*TP,id).map,SRC_I(*TP,id).Y+1,SRC_I(*TP,id).X)!='#'))
						{
							PPOS(*P)=MakePOINT(SRC_I(*TP,id).X,SRC_I(*TP,id).Y+1,SRC_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
						else if((SRC_I(*TP,id).X-1>=0)&&(MAPLOC((*M),SRC_I(*TP,id).map,SRC_I(*TP,id).Y,SRC_I(*TP,id).X-1)!='#'))
						{
							PPOS(*P)=MakePOINT(SRC_I(*TP,id).X-1,SRC_I(*TP,id).Y,SRC_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
						else if ((SRC_I(*TP,id).X+1<=KOL(*M,SRC_I(*TP,id).map))&&(MAPLOC((*M),SRC_I(*TP,id).map,SRC_I(*TP,id).Y,SRC_I(*TP,id).X+1)!='#'))
						{
							PPOS(*P)=MakePOINT(SRC_I(*TP,id).X+1,SRC_I(*TP,id).Y,SRC_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
				}
			}
			}
			else
			{

			if (chr_dest=='M') //Cek Medicine
			{
				Heal(P); //Menambah HP
				CopyKata("Got a Medicine ! HP + 20",MSG);
				MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y-1,PPOS(*P).X)=PLAYERLOGO;
				MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PATHLOGO;
				PPOS(*P).Y-=1;
				
			}
			else if ( chr_dest=='E' ) //Cek Enemy
			{
				//Masuk SKEMA BATTLE
				Monster Mon;
				boolean Win;
				Queue Q;
				CreateMonster(&Mon,"MOrA",1,0);
    			CreateEmpty(&Q,40);
    			movequeue(&Q);
    			battle(P, &Mon,Q,&Win);
    			if(Win)
    			{
      			printf("YOU WIN");
      			printf("\n");
      			MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y-1,PPOS(*P).X)=PLAYERLOGO;
				MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PATHLOGO;
				PPOS(*P).Y-=1;
    			}
			}
			else
			{
				MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y-1,PPOS(*P).X)=PLAYERLOGO;
				MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PATHLOGO;
				PPOS(*P).Y-=1;
			}
			
				
			
			}
		}	
	}
	else if (IsKataSama(S,"GD"))
	{
		POINT PDest=MakePOINT(PPOS(*P).X,PPOS(*P).Y+1,PPOS(*P).map);
		char chr_dest=MAPLOC((*M),PPOS(*P).map,PDest.Y,PDest.X);
		
		if ((PDest.Y<=BRS(*M,PPOS(*P).map))&&(chr_dest!=PAGARLOGO)) //validasi
		{
			if (('0'<=chr_dest)&&(chr_dest<='9')) //Cek portal //Kasus khusus
			{
				if (('0'<=chr_dest)&&(chr_dest<='9')) //Cek portal //Kasus khusus
			{
				int id=SearchPairId(*TP,chr_dest); //pasti ketemu
				if (EQ(SRC_I(*TP,id),PDest)) /*MASIH BINGUNG*/
				{
						MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PATHLOGO;

						if ((DEST_I(*TP,id).Y-1>=0)&&(MAPLOC((*M),DEST_I(*TP,id).map,DEST_I(*TP,id).Y-1,DEST_I(*TP,id).X)!='#'))//Cek atas visibel
						{
							PPOS(*P)=MakePOINT(DEST_I(*TP,id).X,DEST_I(*TP,id).Y-1,DEST_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
						else if((DEST_I(*TP,id).Y+1<=BRS(*M,DEST_I(*TP,id).map))&&(MAPLOC((*M),DEST_I(*TP,id).map,DEST_I(*TP,id).Y+1,SRC_I(*TP,id).X)!='#'))
						{
							PPOS(*P)=MakePOINT(DEST_I(*TP,id).X,DEST_I(*TP,id).Y+1,DEST_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
						else if((DEST_I(*TP,id).X-1>=0)&&(MAPLOC((*M),DEST_I(*TP,id).map,DEST_I(*TP,id).Y,DEST_I(*TP,id).X-1)!='#'))
						{
							PPOS(*P)=MakePOINT(DEST_I(*TP,id).X-1,DEST_I(*TP,id).Y,DEST_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
						else if ((DEST_I(*TP,id).X+1<=KOL(*M,DEST_I(*TP,id).map))&&(MAPLOC((*M),DEST_I(*TP,id).map,DEST_I(*TP,id).Y,SRC_I(*TP,id).X+1)!='#'))
						{
							PPOS(*P)=MakePOINT(DEST_I(*TP,id).X+1,DEST_I(*TP,id).Y,DEST_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
						
				}
				else if (EQ(DEST_I(*TP,id),PDest))
				{
						MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PATHLOGO;

						if ((SRC_I(*TP,id).Y-1>=0)&&(MAPLOC((*M),SRC_I(*TP,id).map,SRC_I(*TP,id).Y-1,SRC_I(*TP,id).X)!='#'))//Cek atas visibel
						{
							PPOS(*P)=MakePOINT(SRC_I(*TP,id).X,SRC_I(*TP,id).Y-1,SRC_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
						else if((SRC_I(*TP,id).Y+1<=BRS(*M,SRC_I(*TP,id).map))&&(MAPLOC((*M),SRC_I(*TP,id).map,SRC_I(*TP,id).Y+1,SRC_I(*TP,id).X)!='#'))
						{
							PPOS(*P)=MakePOINT(SRC_I(*TP,id).X,SRC_I(*TP,id).Y+1,SRC_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
						else if((SRC_I(*TP,id).X-1>=0)&&(MAPLOC((*M),SRC_I(*TP,id).map,SRC_I(*TP,id).Y,SRC_I(*TP,id).X-1)!='#'))
						{
							PPOS(*P)=MakePOINT(SRC_I(*TP,id).X-1,SRC_I(*TP,id).Y,SRC_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
						else if ((SRC_I(*TP,id).X+1<=KOL(*M,SRC_I(*TP,id).map))&&(MAPLOC((*M),SRC_I(*TP,id).map,SRC_I(*TP,id).Y,SRC_I(*TP,id).X+1)!='#'))
						{
							PPOS(*P)=MakePOINT(SRC_I(*TP,id).X+1,SRC_I(*TP,id).Y,SRC_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
				}
			}
			}

			else
			{

			if (chr_dest=='M') //Cek Medicine
			{
				Heal(P); //Menambah HP
				CopyKata("Got a Medicine ! HP + 20",MSG);
				MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y+1,PPOS(*P).X)=PLAYERLOGO;
				MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PATHLOGO;
				PPOS(*P).Y+=1;
			}
			else if ( chr_dest=='E' ) //Cek Enemy
			{
				//Masuk SKEMA BATTLE
				Monster Mon;
				boolean Win;
				Queue Q;
				CreateMonster(&Mon,"MOMO",1,0);
    			CreateEmpty(&Q,40);
    			movequeue(&Q);
    			battle(P, &Mon,Q,&Win);
    			if(Win)
    			{
      			printf("YOU WIN");
      			printf("\n");
      			
      			MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y+1,PPOS(*P).X)=PLAYERLOGO;
			MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PATHLOGO;
			PPOS(*P).Y+=1;
    			}
			}
			else
			{
			MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y+1,PPOS(*P).X)=PLAYERLOGO;
			MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PATHLOGO;
			PPOS(*P).Y+=1;
			}
			}
		}	
	}
	else if (IsKataSama(S,"GL"))
	{
		POINT PDest=MakePOINT(PPOS(*P).X-1,PPOS(*P).Y,PPOS(*P).map);
		char chr_dest=MAPLOC((*M),PPOS(*P).map,PDest.Y,PDest.X);
		if ((PDest.X>=0)&&(chr_dest!=PAGARLOGO)) //validasi
		{
			if (('0'<=chr_dest)&&(chr_dest<='9')) //Cek portal //Kasus khusus
			{
				int id=SearchPairId(*TP,chr_dest); //pasti ketemu
				if (EQ(SRC_I(*TP,id),PDest)) /*MASIH BINGUNG*/
				{
						MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PATHLOGO;

						if ((DEST_I(*TP,id).Y-1>=0)&&(MAPLOC((*M),DEST_I(*TP,id).map,DEST_I(*TP,id).Y-1,DEST_I(*TP,id).X)!='#'))//Cek atas visibel
						{
							PPOS(*P)=MakePOINT(DEST_I(*TP,id).X,DEST_I(*TP,id).Y-1,DEST_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
						else if((DEST_I(*TP,id).Y+1<=BRS(*M,DEST_I(*TP,id).map))&&(MAPLOC((*M),DEST_I(*TP,id).map,DEST_I(*TP,id).Y+1,SRC_I(*TP,id).X)!='#'))
						{
							PPOS(*P)=MakePOINT(DEST_I(*TP,id).X,DEST_I(*TP,id).Y+1,DEST_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
						else if((DEST_I(*TP,id).X-1>=0)&&(MAPLOC((*M),DEST_I(*TP,id).map,DEST_I(*TP,id).Y,DEST_I(*TP,id).X-1)!='#'))
						{
							PPOS(*P)=MakePOINT(DEST_I(*TP,id).X-1,DEST_I(*TP,id).Y,DEST_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
						else if ((DEST_I(*TP,id).X+1<=KOL(*M,DEST_I(*TP,id).map))&&(MAPLOC((*M),DEST_I(*TP,id).map,DEST_I(*TP,id).Y,SRC_I(*TP,id).X+1)!='#'))
						{
							PPOS(*P)=MakePOINT(DEST_I(*TP,id).X+1,DEST_I(*TP,id).Y,DEST_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
						
				}
				else if (EQ(DEST_I(*TP,id),PDest))
				{

						printf("YE\n");
						MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PATHLOGO;

						if ((SRC_I(*TP,id).Y-1>=0)&&(MAPLOC((*M),SRC_I(*TP,id).map,SRC_I(*TP,id).Y-1,SRC_I(*TP,id).X)!='#'))//Cek atas visibel
						{
							PPOS(*P)=MakePOINT(SRC_I(*TP,id).X,SRC_I(*TP,id).Y-1,SRC_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
						else if((SRC_I(*TP,id).Y+1<=BRS(*M,SRC_I(*TP,id).map))&&(MAPLOC((*M),SRC_I(*TP,id).map,SRC_I(*TP,id).Y+1,SRC_I(*TP,id).X)!='#'))
						{
							PPOS(*P)=MakePOINT(SRC_I(*TP,id).X,SRC_I(*TP,id).Y+1,SRC_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
						else if((SRC_I(*TP,id).X-1>=0)&&(MAPLOC((*M),SRC_I(*TP,id).map,SRC_I(*TP,id).Y,SRC_I(*TP,id).X-1)!='#'))
						{
							PPOS(*P)=MakePOINT(SRC_I(*TP,id).X-1,SRC_I(*TP,id).Y,SRC_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
						else if ((SRC_I(*TP,id).X+1<=KOL(*M,SRC_I(*TP,id).map))&&(MAPLOC((*M),SRC_I(*TP,id).map,SRC_I(*TP,id).Y,SRC_I(*TP,id).X+1)!='#'))
						{
							PPOS(*P)=MakePOINT(SRC_I(*TP,id).X+1,SRC_I(*TP,id).Y,SRC_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
				}
			}

			else
			{

			if (chr_dest=='M') //Cek Medicine
			{
				Heal(P); //Menambah HP
				CopyKata("Got a Medicine ! HP + 20",MSG);
				MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X-1)=PLAYERLOGO;
				MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PATHLOGO;
				PPOS(*P).X-=1;
			}
			else if ( chr_dest=='E' ) //Cek Enemy
			{
				//Masuk SKEMA BATTLE
				Monster Mon;
				boolean Win;
				Queue Q;
				CreateMonster(&Mon,"MOMO",1,0);
    			CreateEmpty(&Q,40);
    			movequeue(&Q);
    			battle(P, &Mon,Q,&Win);
    			if(Win)
    			{
      			printf("YOU WIN");
      			printf("\n");
      			
      			MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X-1)=PLAYERLOGO;
			MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PATHLOGO;
			PPOS(*P).X-=1;
    			}
			}
			else {
			MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X-1)=PLAYERLOGO;
			MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PATHLOGO;
			PPOS(*P).X-=1;
			}
			}
		}	
	}
	else if (IsKataSama(S,"GR"))
	{
		POINT PDest=MakePOINT(PPOS(*P).X+1,PPOS(*P).Y,PPOS(*P).map);
		char chr_dest=MAPLOC((*M),PPOS(*P).map,PDest.Y,PDest.X);
		
		if ((PDest.X<=KOL(*M,PPOS(*P).map))&&(chr_dest!=PAGARLOGO)) //validasi
		{
			if (('0'<=chr_dest)&&(chr_dest<='9')) //Cek portal //Kasus khusus
			{
				if (('0'<=chr_dest)&&(chr_dest<='9')) //Cek portal //Kasus khusus
			{
				int id=SearchPairId(*TP,chr_dest); //pasti ketemu
				if (EQ(SRC_I(*TP,id),PDest)) /*MASIH BINGUNG*/
				{
						MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PATHLOGO;

						if ((DEST_I(*TP,id).Y-1>=0)&&(MAPLOC((*M),DEST_I(*TP,id).map,DEST_I(*TP,id).Y-1,DEST_I(*TP,id).X)!='#'))//Cek atas visibel
						{
							PPOS(*P)=MakePOINT(DEST_I(*TP,id).X,DEST_I(*TP,id).Y-1,DEST_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
						else if((DEST_I(*TP,id).Y+1<=BRS(*M,DEST_I(*TP,id).map))&&(MAPLOC((*M),DEST_I(*TP,id).map,DEST_I(*TP,id).Y+1,SRC_I(*TP,id).X)!='#'))
						{
							PPOS(*P)=MakePOINT(DEST_I(*TP,id).X,DEST_I(*TP,id).Y+1,DEST_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
						else if((DEST_I(*TP,id).X-1>=0)&&(MAPLOC((*M),DEST_I(*TP,id).map,DEST_I(*TP,id).Y,DEST_I(*TP,id).X-1)!='#'))
						{
							PPOS(*P)=MakePOINT(DEST_I(*TP,id).X-1,DEST_I(*TP,id).Y,DEST_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
						else if ((DEST_I(*TP,id).X+1<=KOL(*M,DEST_I(*TP,id).map))&&(MAPLOC((*M),DEST_I(*TP,id).map,DEST_I(*TP,id).Y,SRC_I(*TP,id).X+1)!='#'))
						{
							PPOS(*P)=MakePOINT(DEST_I(*TP,id).X+1,DEST_I(*TP,id).Y,DEST_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
						
				}
				else if (EQ(DEST_I(*TP,id),PDest))
				{
						MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PATHLOGO;

						if ((SRC_I(*TP,id).Y-1>=0)&&(MAPLOC((*M),SRC_I(*TP,id).map,SRC_I(*TP,id).Y-1,SRC_I(*TP,id).X)!='#'))//Cek atas visibel
						{
							PPOS(*P)=MakePOINT(SRC_I(*TP,id).X,SRC_I(*TP,id).Y-1,SRC_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
						else if((SRC_I(*TP,id).Y+1<=BRS(*M,SRC_I(*TP,id).map))&&(MAPLOC((*M),SRC_I(*TP,id).map,SRC_I(*TP,id).Y+1,SRC_I(*TP,id).X)!='#'))
						{
							PPOS(*P)=MakePOINT(SRC_I(*TP,id).X,SRC_I(*TP,id).Y+1,SRC_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
						else if((SRC_I(*TP,id).X-1>=0)&&(MAPLOC((*M),SRC_I(*TP,id).map,SRC_I(*TP,id).Y,SRC_I(*TP,id).X-1)!='#'))
						{
							PPOS(*P)=MakePOINT(SRC_I(*TP,id).X-1,SRC_I(*TP,id).Y,SRC_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
						else if ((SRC_I(*TP,id).X+1<=KOL(*M,SRC_I(*TP,id).map))&&(MAPLOC((*M),SRC_I(*TP,id).map,SRC_I(*TP,id).Y,SRC_I(*TP,id).X+1)!='#'))
						{
							PPOS(*P)=MakePOINT(SRC_I(*TP,id).X+1,SRC_I(*TP,id).Y,SRC_I(*TP,id).map);
							MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PLAYERLOGO;
						}
				}
			}
			}
			else
			{

			if (chr_dest=='M') //Cek Medicine
			{
				Heal(P); //Menambah HP
				CopyKata("Got a Medicine ! HP + 20",MSG);
				MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X+1)=PLAYERLOGO;
			MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PATHLOGO;
			PPOS(*P).X+=1;
			}
			else if ( chr_dest=='E' ) //Cek Enemy
			{
				//Masuk SKEMA BATTLE
				Monster Mon;
				boolean Win;
				Queue Q;
				CreateMonster(&Mon,"MOMO",1,0);
    			CreateEmpty(&Q,40);
    			movequeue(&Q);
    			battle(P, &Mon,Q,&Win);
    			if(Win)
    			{
      			printf("YOU WIN");
      			printf("\n");
      			
      			MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X+1)=PLAYERLOGO;
			MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PATHLOGO;
			PPOS(*P).X+=1;
    			}
			}
			else{
			MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X+1)=PLAYERLOGO;
			MAPLOC((*M),PPOS(*P).map,PPOS(*P).Y,PPOS(*P).X)=PATHLOGO;
			PPOS(*P).X+=1; }
			}
		}	
	}
	else if (IsKataSama(S,"SKILL"))
	{
		ShowSkill(*ST);
	}
	else if (IsKataSama(S,"ABCD"))
	{
		LevelUp(P,ST);
	}
	else if (IsKataSama(S,"EXIT"))
	{
		WinFlag=true;
	}
	/*else if (IsKataSama(S,"SAVE"))
	{
		SavePlayer(T,"FileEksternal/FileKarakter.txt");
	}*/

}

void CetakPair(TabPair TP)
{
	for (int i=0;i<PAIR_LEN(TP);i++)
	{
		printf("%c = %d %d %d  - %d %d %d\n",CHR_PAIR_I(TP,i),MAP_I_Asal(TP,i),SRC_I(TP,i).X,SRC_I(TP,i).Y,MAP_I_Tujuan(TP,i),DEST_I(TP,i).X,DEST_I(TP,i).Y); 
	}
}




int main()
{
	/* Inisialisasi */
	Maps Mp;
	Player P;
	BinTree Skilltree;
	

	TabPair TP; PAIR_LEN(TP)=0;
	
	CreatePlayer(&P,"AZIS");
	initSkillTree(&Skilltree);
	CreateEmpty_Map(&Mp);
	
	Load_Map(&Mp,&P,&TP);
	//TulisMap(M,P);
	
	
	while (!WinFlag)
		Mode_Jelajah(&Mp,&P,&TP,&Skilltree);
	//printf("%d\n",PAIR_LEN(TP));
	CetakPair(TP);
	
	
	
	
	return 0;
}