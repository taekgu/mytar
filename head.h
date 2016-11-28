#ifndef _head_h
#define _head_h

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
int lastHeapIdx;

int charFreq[num_ASCII];

#endif // _head_h
