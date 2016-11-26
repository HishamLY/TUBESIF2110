#include <stdio.h>
#include <stdlib.h>
#include "battle.h"
#include <unistd.h>
#include "mainmenu.h"
#include "stackQ.h"
#include <time.h>
int IntLen(int I)
{
  int i;
  i=1;
  while(I>=10)
  {
    I=I/10;
    i=i+1;
  }
  return(i);
}
void PrintMove(Queue Q, int I)
{
    if(I==1)
    {
      printf("%c##%c",InfoHead(Q),Q.T[((Q).HEAD)+3]);
    }
    else
    {
      if(I==2)
      {
        printf("%c%c##",InfoHead(Q),Q.T[((Q).HEAD)+1]);
      }
      else
      {
        if(I==3)
        {
          printf("%c#%c#",InfoHead(Q),Q.T[((Q).HEAD)+2]);
        }
        else
        {
          if(I==4)
          {
            printf("#%c%c#",Q.T[((Q).HEAD)+1],Q.T[((Q).HEAD)+2]);
          }
          else
          {
            if(I==5)
            {
              printf("#%c#%c",Q.T[((Q).HEAD)+1],Q.T[((Q).HEAD)+3]);
            }
            else
            {
              printf("##%c%c",Q.T[((Q).HEAD)+2],Q.T[((Q).HEAD)+3]);
            }
          }
        }
      }
    }
}

void PrintInterface(Player *P, Monster *M, Queue Q, int Round, Queue *Move, int I)
/*Prosedur interface */
{
  Queue MoveTemp;
  CreateEmpty(&MoveTemp,40);
  char X;
  printf("╔══════════════════════╦══════════════╦══════════════╦══════════════╦══════════════╦══════════════╗");printf("\n");
  printf("║ %s%.*s ║ Level : %d%.*s ║ HP : %d/%d%.*s%.*s ║ STR : %d%.*s  ║ DEF : %d%.*s  ║ Round : %d%.*s ║", Name(*P),(20-StrLen(Name(*P))),"                     ",Level(*P),(4-IntLen(Level(*P))),"                  ",HP(*P),MaxHP(*P),(3-IntLen(HP(*P))),"                        ",(3-IntLen(MaxHP(*P))),"                       ",STR(*P),(5-IntLen(STR(*P))),"                       ",DEF(*P),(5-IntLen(DEF(*P))),"                       ",Round,(4-IntLen(Round)),"                       ");printf("\n");
  printf("╠══════════════════════╬══════════════╬══════════════╩══════════════╩══════════════╩══════════════╣");printf("\n");
  printf("║ %s%.*s ║ HP : %d%.*s  ║ ", Name(*M),(20-StrLen(Name(*M))),"                                     ", HP(*M),(6-IntLen(HP(*M))),"                       ");
  PrintMove(Q,I);
  printf("                                                      ║");
  printf("\n");
  printf("╠══════════════════════╩══════════════╩═══════════════════════════════════════════════════════════╣");printf("\n");
  printf("║ Inserted Command :");
  while(!IsEmpty(*Move))
  {
    Del(Move,&X);
    printf("%c", X);
    Add(&MoveTemp,X);
  }
  while(!IsEmpty(MoveTemp))
  {
    Del(&MoveTemp,&X);
    Add(Move,X);
  }
  printf("%.*s",(4-NBElmt(*Move)),"            ");
  printf("                                                                          ║");printf("\n");
  printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════╝");printf("\n");
  printf("\n");
  printf("Command :");
}

void PrintInterfaceBattle(Player *P, Monster *M, Queue Q, int Round, Queue *Move, int N)
/*Prosedur interface battle*/
{
    int n;
    Queue MoveTemp;
    CreateEmpty(&MoveTemp,40);
    char X;
    n=0;
    printf("╔══════════════════════╦══════════════╦══════════════╦══════════════╦══════════════╦══════════════╗");printf("\n");
    printf("║ %s%.*s ║ Level : %d%.*s ║ HP : %d/%d%.*s%.*s ║ STR : %d%.*s  ║ DEF : %d%.*s  ║ Round : %d%.*s ║", Name(*P),(20-StrLen(Name(*P))),"                     ",Level(*P),(4-IntLen(Level(*P))),"                  ",HP(*P),MaxHP(*P),(3-IntLen(HP(*P))),"                        ",(3-IntLen(MaxHP(*P))),"                       ",STR(*P),(5-IntLen(STR(*P))),"                       ",DEF(*P),(5-IntLen(DEF(*P))),"                       ",Round,(4-IntLen(Round)),"                       ");printf("\n");
    printf("╠══════════════════════╬══════════════╬══════════════╩══════════════╩══════════════╩══════════════╣");printf("\n");
    printf("║ %s%.*s ║ HP : %d%.*s  ║ ", Name(*M),(20-StrLen(Name(*M))),"                                     ", HP(*M),(6-IntLen(HP(*M))),"                       ");
    printf("%c%c%c%c",InfoHead(Q),Q.T[((Q).HEAD)+1],Q.T[((Q).HEAD)+2],Q.T[((Q).HEAD)+3]);
    printf("                                                      ║");
    printf("\n");
    printf("╠══════════════════════╩══════════════╩═══════════════════════════════════════════════════════════╣");printf("\n");
    printf("║ Inserted Command :");
    while(!IsEmpty(*Move))
    {
      if(n==N)
      {
        printf(">");
      }
      Del(Move,&X);
      printf("%c", X);
      Add(&MoveTemp,X);
      n=n+1;
    }
    while(!IsEmpty(MoveTemp))
    {
      Del(&MoveTemp,&X);
      Add(Move,X);
    }
    printf("%.*s",(4-NBElmt(*Move)),"            ");
    printf("                                                                         ║");printf("\n");
    printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════╝");printf("\n");
}

void damagecalculation(Player *P, Monster *M, boolean win, char inputP)
/* I.S. Input berupa 'A','F' atau 'B' */
/* F.S. Mengupdate nilai HP Player atau Monster setelah Battle */
{

	if (win && ((inputP=='A')||(inputP=='F')))
	{
		if ((2*STR(*P)-DEF(*M))>0)
		{
			HP(*M)=HP(*M)-(2*STR(*P)-DEF(*M));
		}
    if(HP(*M)<0)
    {
      HP(*M)=0;
    }
	}
	else if (!win &&((inputP=='A')||(inputP=='F')))
	{
		if ((2*STR(*M)-DEF(*P))>0)
		{
			HP(*P)=HP(*P)-(2*STR(*M)-DEF(*P));
		}
    if(HP(*P)<0)
    {
      HP(*P)=0;
    }
	}
}

void Suit(Player *P, Monster *M, char MovPlayer, char MovEnemy, Queue Q, int Round, Queue *Move, int N)
/*I.S. info Player dan monster terdefinisi. Move Player dan Monster terdefinisi
F.S. Menampilkan pesan battle, memperbarui statistik monster dan player*/
{
    if (MovPlayer=='A')
    {
        if (MovEnemy=='A')
        {
          if ((2*STR(*P)-DEF(*M))>0)
      		{
      			HP(*M)=HP(*M)-(2*STR(*P)-DEF(*M));
      		}
          if(HP(*M)<0)
          {
            HP(*M)=0;
          }
          if ((2*STR(*M)-DEF(*P))>0)
      		{
      			HP(*P)=HP(*P)-(2*STR(*M)-DEF(*P));
      		}
          if(HP(*P)<0)
          {
            HP(*P)=0;
          }
          PrintInterfaceBattle(P, M, Q, Round, Move, N);
          printf("YOU AND YOUR ENEMY ATTACKED EACH OTHER!\n");
        }
        else if (MovEnemy=='B')
        {
          PrintInterfaceBattle(P, M, Q, Round, Move, N);
          printf("%s ATTACKED\n",Name(*P));
          printf("BUT %s BLOCKED IT!!\n", Name(*M));
        }
        else if (MovEnemy=='F')
        {
          damagecalculation(P,M,true,MovPlayer);
          PrintInterfaceBattle(P, M, Q, Round, Move, N);
          printf("%s TRIED TO FLANK %s\n",Name(*M), Name(*P));
          printf("BUT IT IS COUNTERED BY %s\n", Name(*P));
        }
    }
    else if (MovPlayer=='B')
    {
        if (MovEnemy=='A')
        {
          PrintInterfaceBattle(P, M, Q, Round, Move, N);
          printf("%s ATTACKED\n",Name(*M));
          printf("BUT %s BLOCKED IT!!\n", Name(*P));
        }
        else if (MovEnemy=='B')
        {
          PrintInterfaceBattle(P, M, Q, Round, Move, N);
           printf("YOU AND YOUR ENEMY USE THE SAME MOVE\n");
        }
        else if (MovEnemy=='F')
        {
          damagecalculation(P,M,false,MovEnemy);
          PrintInterfaceBattle(P, M, Q, Round, Move, N);
            printf("%s FLANKED %s\n",Name(*M), Name(*P));
        }
    }
    else if (MovPlayer=='F')
    {
        if (MovEnemy=='A')
        {
          damagecalculation(P,M,false,MovEnemy);
            PrintInterfaceBattle(P, M, Q, Round, Move, N);
            printf("%s TRIED TO FLANK %s\n",Name(*P), Name(*M));
            printf("BUT IT IS COUNTERED BY %s\n", Name(*M));

        }
        else if (MovEnemy=='B')
        {
          damagecalculation(P,M,true,MovPlayer);
          PrintInterfaceBattle(P, M, Q, Round, Move, N);
            printf("%s FLANKED %s\n",Name(*P), Name(*M));

        }
        else if (MovEnemy=='F')
        {
          PrintInterfaceBattle(P, M, Q, Round, Move, N);
             printf("YOU AND YOUR ENEMY USE THE SAME MOVE\n");
        }
    }
}

void battle(Player *P, Monster *M, StackQ S, boolean *Win)
/*Prosedur battle*/
/*I.S : Player akan beraarung dengan monster*/
/*F.S : BIla berhasil menang, Monster akan hilang dan player
mendapat exp, Win=true. Jika kalah, player hanya mendapat setengah
exp dan Win=false.
*/
{
  /*Kamus*/
  int Round;
  int N,I,b,j;
  infotype_Q X,Y;
  Queue Move, MoveP, MoveM,Q;
  char MovPlayer, MovEnemy,D;
  /* code */
  Round=1;
  clear();
  if(Boss(*M)==1)
  {
    j=80;
  }
  else
  {
    j=40;
  }
  CreateEmpty(&Move,j);
  CreateEmpty(&MoveM,j);
  CreateEmpty(&MoveP,j);
  if(Boss(*M)==1)
  {
    b=20;
  }
  else
  {
    b=10;
  }
  while((Round<=b)&&(HP(*P)>0)&&(HP(*M)>0))
  {
    I=rand()%6;
    PopSQ(&S,&Q);
    while (NBElmt(Move)<4)
    {
      PrintInterface(P, M, Q, Round, &Move,I);
      scanf("%s",&X);
      if(X=='E')
      {
        while(!IsEmpty(Move))
        {
          Del(&Move, &Y);
        }
      }
      else
      {
        if((X=='A')||(X=='B')||(X=='F'))
        {
          Add (&Move, X);
        }
        else
        {

        }
      }
      clear();
    }
    MoveM=Q;
    MoveP=Move;
    N=0;
    while((!IsEmpty(MoveP))&&(HP(*P)>0)&&(HP(*M)>0))
    {
      Del (&MoveM, &MovEnemy);
      Del (&MoveP, &MovPlayer);
      Suit(P, M, MovPlayer, MovEnemy, Q,Round,&Move,N);
      N=N+1;
      usleep(1000000);
      clear();
    }
    while(!IsEmpty(Move))
    {
      Del(&Move, &X);
    }
    Round=Round+1;
    int i;
    i=0;
    while(i<4){
      Del (&Q, &D);
      i=i+1;
    }
  }
  if(HP(*M)==0)
  {
    *Win=true;
  }
  else
  {
    *Win=false;
  }
}
