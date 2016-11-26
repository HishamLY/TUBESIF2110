#include <stdio.h>
#include <stdlib.h>
#include "Skilltree.h"

int main()
{
    BinTree Skilltree;

    initSkillTree(&Skilltree);
    PrintTree(Skilltree,2);
    ShowSkill(Skilltree);

    InterfaceSkill(&Skilltree);

    ShowSkill(Skilltree);
    InterfaceSkill(&Skilltree);
    PrintTree(Skilltree,2);

    return 0;
}
