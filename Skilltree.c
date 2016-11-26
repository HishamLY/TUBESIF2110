#include "Skilltree.h"
#include "bintree.h"

/*Definisi Skill Tree:
-Bentuk skill tree sesuai dengan yang ada di gambar
-implementasi skill tree adalah dengan integer
-skill yang sudah diambil bernilai positif, sedangkan yang belum bernilai negatif
*/

void initSkillTree(BinTree *T)
/*I.S. T sembarang
F.S. T berbentuk sesuai gambar*/
{
    BinTree S1,S2,S3,S4,S5,S6,S7,S8,S9;

    /*level 3*/
    MakeTree(-8,Nil,Nil,&S8);
    MakeTree(-9,Nil,Nil,&S9);

    /*level 2*/
    MakeTree(-4,Nil,Nil,&S4);
    MakeTree(-5,S8,Nil,&S5);
    MakeTree(-6,S9,Nil,&S6);
    MakeTree(-7,Nil,Nil,&S7);

    /*level 1*/
    MakeTree(-2,S4,S5,&S2);
    MakeTree(-3,S6,S7,&S3);

    /*level 0*/
    MakeTree(1,S2,S3,&S1);

    /*return value*/
    *T=S1;
}

void TulisSkill(int no)
/*I.S. T dan no terdefinisi
F.S. Menulis skill sesuai no*/
{
    /*basis*/
    if (no==1)
    {
        printf("1. Enable Flank Attack\n");
    }
    if (no==2)
    {
        printf("2. Add +1 STR\n");
    }
    if (no==3)
    {
        printf("3. Add +1 DEF\n");
    }
    if (no==4)
    {
        printf("4. Reveals One enemy move per turn\n");
    }
    if (no==5)
    {
        printf("5. Add +5 Max HP\n");
    }
    if (no==6)
    {
        printf("6. Add +5 Max HP\n");
    }
    if (no==7)
    {
        printf("7. Reveals One enemy move per turn\n");
    }
    if (no==8)
    {
        printf("8. Add +2 STR\n");
    }
    if (no==9)
    {
        printf("9. Add +2 DEF\n");
    }
}

void ShowSkill(BinTree T)
/*I.S. T terdefinisi
F.S. menulis skill-skill yang sudah diambil.*/
{
    if ((!IsTreeEmpty(T))&&(Akar(T)>0))
    {
            TulisSkill(Akar(T));
            ShowSkill(Left(T));
            ShowSkill(Right(T));
    }
}

boolean IsSkillLearned(BinTree T, int no)
/*return true bila skill sudah diperoleh*/
{
    if (Akar(T)==no)
    {
        return true;
    }
    else if (Akar(T)==-no)
    {
        return false;
    }
    else
    {
        if ((SearchTree(Left(T),no))||((SearchTree(Left(T),-no))))
        {
            return SearchTree(Left(T),no);
        }
        else
        {
             return SearchTree(Right(T),no);
        }
    }
}
boolean IsSkillAvailable(BinTree P, int no)
/*Mengembalikan true jika skill dapat diambil dan false jika tidak*/
{
    if (no==1)
    {
        return false;
    }
    else if (no==2)
    {
        return (IsSkillLearned(P,1))&&(!IsSkillLearned(P,no));
    }
    else if (no==3)
    {
        return (IsSkillLearned(P,1))&&(!IsSkillLearned(P,no));
    }
    else if (no==4)
    {
        return (IsSkillLearned(P,2))&&(!IsSkillLearned(P,no));
    }
    else if (no==5)
    {
        return (IsSkillLearned(P,2))&&(!IsSkillLearned(P,no));
    }
    else if (no==6)
    {
        return (IsSkillLearned(P,3))&&(!IsSkillLearned(P,no));
    }
    else if (no==7)
    {
        return (IsSkillLearned(P,3))&&(!IsSkillLearned(P,no));
    }
    else if (no==8)
    {
        return (IsSkillLearned(P,5))&&(!IsSkillLearned(P,no));
    }
    else if (no==9)
    {
        return (IsSkillLearned(P,6))&&(!IsSkillLearned(P,no));
    }
    else
    {
        return false;
    }
    /*
    if (!IsTreeEmpty(P))
    {
        if ((Akar(P)>0)&&((Akar(Left(P))<0)||(Akar(Right(P))<0)))
        {
            if (!IsTreeEmpty(Left(P)))
                {
                    return (Akar(Left(P))==-no);
                }
            else if (!IsTreeEmpty(Right(P)))
                {
                    return (Akar(Right(P))==-no);
                }
            else
            {
                return false;
            }
        }
        else
        {
            return ((IsSkillAvailable(Left(P),no))||(IsSkillAvailable(Right(P),no)));
        }
    }
    else
    {
        return false;
    }
    */
}
void AvailableSkill(BinTree T)
/*I.S. T terdefinisi
F.S. menulis skill-skill yang dapat diambil.*/
{
    int i;

    for (i=1;i<=9;i++)
    {
        if (IsSkillAvailable(T,i))
        {
            TulisSkill(i);
        }
    }
}

void AmbilSkill(BinTree *T, int no, Player *P1)
/*I.S. T dan no terdefinisi. no adalah nomor skill yang dapat diambil
F.S. skill dengan nomor skill no. diambil (nilainya diubah menjadi positif)*/
{

    int neg=0-no;
    /*basis*/
    if (Akar(*T)==neg)
    {
        Akar(*T)=no;
    }
    else
    {
        if (SearchTree(Left(*T),neg))
        {
            AmbilSkill(&Left(*T),no,P1);
        }
        else
        {
            AmbilSkill(&Right(*T),no,P1);
        }
    }

    

}

void InterfaceSkill(BinTree *T, Player *P1)
/*I.S. T adalah Skill Tree. *T Terdefinisi.
F.S. Menampilkan interface pengambilan skill.
 Menerima dan memvalidasi input. Mengambil skill dan mengupdate skill tree*/
 {
    int no;

    printf("One Skill Point Available! Spend Skill Point to Learn Skill\n");
    printf("Skill Available: \n");
    AvailableSkill(*T);
    /*Input dan validasi nomor skill*/
    printf("Choose Skill (select skill number): ");
    scanf("%d", &no);
    while (!IsSkillAvailable(*T,no))
    {
        printf("wrong input. Please try again.\n");
        printf("Choose Skill (select skill number): ");
        scanf("%d", &no);
    }

    /*Proses mendapatkan skill*/
    AmbilSkill(T,no,P1);
    switch(no)
    {
        case 2 : {STR(*P1)++;
                 break;}
        case 3 : {DEF(*P1)++;
                 break;}
        case 4 : {MaxHP(*P1)=MaxHP(*P1)+15;
                 break;}
        case 5 : {STR(*P1)=STR(*P1)+2;
                 break;}
        case 6 : {DEF(*P1)=DEF(*P1)+2;
                 break;}
        case 7 : {MaxHP(*P1)=MaxHP(*P1)+20;
                 break;}
        case 8 : {STR(*P1)=STR(*P1)+5;
                 DEF(*P1)=DEF(*P1)+3;
                 break;}
        case 9 : {STR(*P1)=STR(*P1)+3;
                 DEF(*P1)=DEF(*P1)+5;
                 break;}
    } 
 }
