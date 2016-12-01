#include "head.h"

void traverse(struct node * cur, char c)
{
	codeBufIdx++;
	codeBuf[codeBufIdx] = c;
	codeBuf[codeBufIdx + 1] = 0;

	if(cur->left == 0 && cur->right == 0)
	{
		printf("character %d (%c): %s\n", (int)cur->c, cur->c, codeBuf);
		
		char *hufCode = (char *)malloc(strlen(codeBuf)+1);
		strcpy(hufCode, codeBuf);
		symCode[(int)cur->c] = hufCode;
	}
	else{
		traverse(cur->left, '0');
		traverse(cur->right, '1');
	}
	codeBuf[codeBufIdx] = 0;
        codeBufIdx--;
        return;
}
