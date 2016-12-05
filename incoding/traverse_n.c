#include "head.h"

void traverse_n(struct node * cur, char c)
{
	codeBufIdx++;
	codeBuf[codeBufIdx] = c;
	codeBuf[codeBufIdx + 1] = 0;

	if(cur->left == 0 && cur->right == 0)
	{
		char *hufCode = (char *)malloc(strlen(codeBuf)+1);
		strcpy(hufCode, codeBuf);
		symCode[(int)cur->c] = hufCode;
	}
	else{
		traverse_n(cur->left, '0');
		traverse_n(cur->right, '1');
	}
	codeBuf[codeBufIdx] = 0;
        codeBufIdx--;
        return;
}
