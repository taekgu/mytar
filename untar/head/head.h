#ifndef _head_h
#define _head_h

// incoding head
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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
char codeBuf[100];
int codeBufIdx;

int charFreq[num_ASCII];
char *symCode[num_ASCII];

void tree_loadHuff(struct node *cur, char c);
void tree_loadHuff_n(struct node *cur, char c);
void writeData(char *fName);
void writeData(char *fName);
#endif // _head_h
