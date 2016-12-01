#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct huffNode
{
	short value;
	int freq; 
	struct huffNode* left;
	struct huffNode* right;
}huffNode;
