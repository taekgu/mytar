#include "head.h"

void tree_loadHuff_n(struct node *cur, char c)
{
        codeBufIdx++;
        codeBuf[codeBufIdx] = c;
        codeBuf[codeBufIdx+1] = 0;

        if(cur->left == 0 && cur->right == 0)
        {
		printf("character %d (%c) : %s\n",(int)cur->c,cur->c,codeBuf);
        }
        else
        {
                tree_loadHuff(cur->left,'0');
                tree_loadHuff(cur->right,'1');
        }
        codeBuf[codeBufIdx] = 0;
        codeBufIdx--;
        return;
}


