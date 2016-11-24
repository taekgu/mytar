// incoding head
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define buf_SZ 100
#define num_ASCII 256

struct node
{
	char c;
	int frequency;
	struct node *left;
	struct node *right;
};

struct node ** heap;
int lastHeapIdx = 0;

int charFreq[num_ASCII];

