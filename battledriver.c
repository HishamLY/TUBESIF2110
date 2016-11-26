#include <stdio.h>
#include <stdlib.h>
#include "battle.h"
#include "mainmenu.h"
#include <time.h>
void movequeue(Queue *Q)
{
  int i, a;
    //Queue Q;
    // CreateEmpty(Q,40);
    i=0;

    while(i!=4)
    {
      a=rand()%3;
      if (a==1) {
      Add(Q,'F');
      }
      else
      {
        if (a==2) {
        Add(Q,'A');
        }
        else
        {
          Add(Q,'B');
        }
      }
      i=i+1;
    }

}

void makeStackQ(StackQ *S)
{
  infotype_SQ X;
  int i;
  i=0;
  CreateEmpty(&X,5);
  while(i!=10)
  {
    movequeue(&X);
    PushSQ(S,X);
    i=i+1;
  }
}
//
//
//
//
//
//
//DRIVER
int main()
{
  srand(time(NULL));
    Player P;
    Monster M;
    Queue Q;
    StackQ S;
    boolean Win;
    int R;
    R=0;
    int lvl,bos;
    char a[25],b[25];
    float x=1.0,y=1.0,x1=2.0,y1=2.0;
    lvl=1;
    bos=0;
    clear();
    printf("Input nama player :");
    scanf("%s",a);
    printf("Input nama monster :");
    scanf("%s",b);
    CreatePlayer(&P,a);
    CreateMonster(&M,b,lvl,bos);
    CreateEmptySQ(&S);

    makeStackQ(&S);
    battle(&P, &M,S,&Win);
    printf("\n");
    if(Win)
    {
      printf("YOU WIN");
      printf("\n");
    }
    return 0;
}
