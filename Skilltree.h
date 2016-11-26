#ifndef SKILLTREE_H_INCLUDED
#define SKILLTREE_H_INCLUDED

#include "bintree.h"
#include "tipedata.h"

/*Definisi Skill Tree:
-Bentuk skill tree sesuai dengan yang ada di gambar
-implementasi skill tree adalah dengan integer
-skill yang sudah diambil bernilai positif, sedangkan yang belum bernilai negatif
*/

void initSkillTree(BinTree *T);
/*I.S. T sembarang
F.S. T berbentuk sesuai gambar*/

void TulisSkill(int no);
/*I.S. T dan no terdefinisi
F.S. Menulis skill sesuai no*/

void ShowSkill(BinTree T);
/*I.S. T terdefinisi
F.S. menulis skill-skill yang sudah diambil.*/

boolean IsSkillLearned(BinTree T, int no);
/*return true bila skill sudah diperoleh*/

boolean IsSkillAvailable(BinTree P, int no);
/*Mengembalikan true jika skill dapat diambil dan false jika tidak*/

void AvailableSkill(BinTree T);
/*I.S. T terdefinisi
F.S. menulis skill-skill yang dapat diambil.*/


void AmbilSkill(BinTree *T, int no, Player *P1);
/*I.S. T dan no terdefinisi
F.S. skill dengan nomor skill no. diambil (nilainya diubah menjadi positif)*/

void InterfaceSkill(BinTree *T, Player *P1);
/*I.S. *T Terdefinisi
F.S. Menampilkan interface pengambilan skill.
 Menerima dan memvalidasi input. Mengambil skill dan mengupdate skill tree*/

#endif // SKILLTREE_H_INCLUDED
