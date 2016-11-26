#ifndef  battle_H
#define battle_H

#include "ADTKarakter.h"
#include "queue.h"
#include "stackQ.h"
int IntLen(int I);

void PrintMove(Queue Q, int I);

void PrintInterface(Player *P, Monster *M, Queue Q, int Round, Queue *Move, int I);
/*Prosedur interface*/


void PrintInterfaceBattle(Player *P, Monster *M, Queue Q, int Round, Queue *Move, int N);
/*Prosedur interface battle*/

void damagecalculation(Player *P, Monster *M, boolean win, char inputP);
/* I.S. Input berupa 'A','F' atau 'B' */
/* F.S. Mengupdate nilai HP Player atau Monster setelah Battle */


void Suit(Player *P, Monster *M, char MovPlayer, char MovEnemy, Queue Q, int Round, Queue *Move, int N);
/*I.S. info Player dan monster terdefinisi. Move Player dan Monster terdefinisi
F.S. Menampilkan pesan battle, memperbarui statistik monster dan player*/

void battle(Player *P, Monster *M, StackQ S, boolean *Win);
/*Prosedur battle*/
/*I.S : Player akan beraarung dengan monster*/
/*F.S : BIla berhasil menang, Monster akan hilang dan player
mendapat exp, Win=true. Jika kalah, player hanya mendapat setengah
exp dan Win=false.
*/



#endif
