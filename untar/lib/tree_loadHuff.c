#include "head.h"

void tree_loadHuff(struct node *cur, char c)
{
        codeBufIdx++;
        codeBuf[codeBufIdx] = c;
        codeBuf[codeBufIdx+1] = 0;

        if(cur->left == 0 && cur->right == 0)
        {
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


