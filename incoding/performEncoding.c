#include "head.h"

// Lee Seung Bin write this code
/*
#define buf_SZ 100
#define num_ASCII 256
int charFreq[num_ASCII];
void showCharFrequency(void) 
*/

void performEncoding(char* fName)
{
	FILE* fin;
	char buf[buf_SZ];
	int i = 0;
	int j = 0;
	struct node *temp;// = (struct node*)malloc(sizeof(struct node));
	fin = fopen(fName, "rt");
	if(fin == 0)
	{
		printf("Unable to open %s. Program terminated \n", fName);
		return;
	}
	
	memset(charFreq, 0, num_ASCII*sizeof(int));
	while(fgets(buf, buf_SZ, fin) != 0)
	{
		int len = strlen(buf);
		for(i = 0;  i < len; i++)
		{
			charFreq[(int)buf[i]]++;
		}
	}
	
	showCharFrequency();
	
	int cnt = countNonZeroCharacters();
	heap = (struct node **)malloc((cnt+1)*sizeof(struct node *));
	memset(heap, 0, (cnt+1)*sizeof(struct node*));
	
	for(i = 0; i< num_ASCII; i++)
	{
		if(charFreq[i]>0)
		{
			struct node *cur = (struct node *)malloc(sizeof(struct node));
			cur->c = (char)i;
			cur->frequency = charFreq[i];
			cur->left = cur->right = 0;
			addToHeap(cur);
		}
	}

	printf("root %d (%c) : %d\n",(int)heap[1]->c, heap[1]->c, heap[1]->frequency);

	//temp = (struct node *)deleteFromHeap();
	
	//printf("previous root %d (%c) : %d\n", (int)temp->c, temp->c, temp->frequency);
	//printf("root %d (%c) : %d\n", (int)heap[1]->c, heap[1]->c, heap[1]->frequency);

	struct node *first = 0;
	struct node *second = 0;

	while(1)
	{
		first = (struct node *)deleteFromHeap();
		second = (struct node *)deleteFromHeap();

		if(second == 0)
		{
			printf("Huffman tree building ended\n");
			break;
		}
		struct node* newOne = (struct node*)malloc(sizeof(struct node));
		newOne->c = 0;
		newOne->frequency = first ->frequency + second -> frequency;
		newOne->left = first;
		newOne->right = second;

		addToHeap(newOne);
	}

	memset(symCode, 0, sizeof(symCode));

	traverse(first->left, '0');
	traverse(first->right, '1');

	int numOfSym = 0;

	for(i =0; i<num_ASCII; i++)
	{
		if(symCode[i] != 0)
		{
			numOfSym++;
			printf("Symbol %c ==> %s\n", (char)i, symCode[i]);
		}
	}

	printf("Number of symbols is %d\n", numOfSym);

	char outputFileName[100];
	char *period = strchr(fName, (int)'.');
	strncpy(outputFileName, fName, (int)(period - fName));
	outputFileName[(int)(period - fName)] = 0;
	strcat(outputFileName,".myzip");

	printf("Output file name is %s\n", outputFileName);

	FILE *fout = 0;
	fout = fopen(outputFileName, "wb");
	if(fout!=0)
	{
		fwrite(&numOfSym, sizeof(numOfSym), 1, fout);
		
		char writeBuf[100];
		for(i=0; i<num_ASCII; i++)
		{
			if(symCode[i] != 0)
			{
				writeBuf[0] = (char)i;
				writeBuf[1] = (char)strlen(symCode[i]);
				strcpy(&writeBuf[2], symCode[i]);
				fwrite(writeBuf, sizeof(char), 2+strlen(symCode[i]), fout);
			}
		}

		FILE *fin;
		fin = fopen(fName, "rt");
		if(fin != 0)
		{
			int locTotalNumBit;
			locTotalNumBit = ftell(fout);
		
			if(fseek(fout, 4, SEEK_CUR) != 0)
			{
				printf("Failed to move the file pointer \n");
				fclose(fin);
				fclose(fout);
				return;
			}

			char bitBuf[buf_SZ];
			int bitBufIdx = 0;
			int bitShiftCnt = 7;
			int totalBitNum = 0;
			char flag = 0;

			memset(bitBuf, 0, buf_SZ);

			while(fgets(buf, buf_SZ, fin) != 0)
			{
				int len = strlen(buf);
				for(i = 0; i<len; i++)
				{
					char *huffmanCode = symCode[(int)buf[i]];
					for(j = 0; j<strlen(huffmanCode); j++)
					{
						char val = 0;
						if(huffmanCode[j] == '0')
						{
							val = 0;
						}else if(huffmanCode[j] == '1')
						{
							val = 1;
						}
						else
						{
							printf("---------critical eroor---------\n");
						}
					
						val = val << bitShiftCnt;
						bitShiftCnt--;

						bitBuf[bitBufIdx] |= val;
						flag = 1;
						totalBitNum++;
						if(bitShiftCnt < 0)
						{
							bitShiftCnt = 7;
							bitBufIdx++;
							if(bitBufIdx >= buf_SZ)
							{
								fwrite(bitBuf, 1, buf_SZ, fout);
								flag = 0;
								bitBufIdx = 0;
								memset(bitBuf, 0, buf_SZ);
							}
						}
					}
				}
			}

			if(flag == 1)
			{
				fwrite(bitBuf, 1, bitBufIdx+1, fout);
			}

			if(fseek(fout, locTotalNumBit, SEEK_SET) == 0)
			{
				fwrite(&totalBitNum, sizeof(totalBitNum),1, fout);
			}else{
				printf("Unable to record total number of bits\n");
			}

			fclose(fin);
		}
		else
		{
			printf("Unable to open the file %s\n", fName);
		}

		fclose(fout);
	}
	else
	{
		printf("Error : unable to open %s\n",outputFileName);
	}

}
