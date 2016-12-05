#include "head.h"

void writeData(char *fName)
{
	FILE *fin = 0;
	int i = 0;
	int j = 0;
	
	fin = fopen(fName,"rb");
	

	if(fin != 0)
	{
		//huffman tree restruct
		int numOfSym = 0;
		fread(&numOfSym,sizeof(int),1,fin);
		
		//how many symbols 
		printf("Number of Symbols is %d \n",numOfSym);

		struct node *huffRoot = (struct node *)malloc(sizeof(struct node));
		huffRoot->left = huffRoot->right = 0;
		struct node *cur = huffRoot;
	
		for(i = 0;i < numOfSym; i++)
		{
			char symbolAndLen[2];//0 = symbol, 1 = length
			fread(symbolAndLen,2,1,fin);
			char buf[100];

			//read huffman code
			fread(buf,1,(int)symbolAndLen[1],fin);
			
			buf[(int)symbolAndLen[1]] = 0;
			printf("%c 's length = %d 's mean = %s\n",symbolAndLen[0],(int)symbolAndLen[1],buf);
			
			cur = huffRoot;
			for(i = 0;i < (int)symbolAndLen[1]; i++)
			{
				if(buf[i] == '0')
				{
					if(cur->left == 0)
					{
						cur->left = (struct node *)malloc(sizeof(struct node));
						cur->left->left = 0;
						cur->left->right = 0;
					}
					cur = cur->left;
				}
				else if(buf[i] == '1')
				{
					if(cur->right == 0)
					{
						cur->right = (struct node *)malloc(sizeof(struct node));
						cur->right->left = 0;
						cur->right->right = 0;
					}
					cur = cur->right;
				}
				else
				{
					printf("--CRITICAL ERROR--\n");
					exit(0);
				}
			}
			cur->c = symbolAndLen[0];
		} //hufman tree recov
		
		//codeBuf[]
		codeBufIdx=-1;
		tree_loadHuff(huffRoot->left,'0');
		tree_loadHuff(huffRoot->right,'1');
		
		//decoding
		FILE *decodedFile;
		char decodedFName[100];
		char *period = strchr(fName,(int)'.');
		strncpy(decodedFName,fName,(int)(period - fName));
		decodedFName[(int)(period-fName)] = 0;
		strcat(decodedFName,".decoded");
		
		decodedFile = fopen(decodedFName,"wt");
		if(decodedFile == 0)
		{
			printf("Unable to create the file %s \n",decodedFName);
			exit(0);
		}
		
		int numBitsToRead = 0;
		fread(&numBitsToRead,sizeof(int),1,fin);
		printf("Total number of bits to read is %d\n",numBitsToRead);
		

		cur = huffRoot;
		char buf[buf_SZ];
		while(1)
		{
			int sz = fread(buf,1,buf_SZ,fin);
			if(sz == 0)
			{
				printf("End of file reached,\n");
				break;
			}
			else
			{
				for(i = 0;i < sz;i++)
				{
						for(j = 0;j < 8;j++)//because byte = 8 bit
						{
							if((char)(buf[i] & 0x80) == 0)
							{
								cur = cur->left;
							}
							else
							{
								cur = cur->right;
							}
							buf[i] = buf[i] << 1;
							numBitsToRead--;
					
							if(cur->left == 0 && cur->right == 0)
							{
								fputc(cur->c,decodedFile);
								cur = huffRoot;
							}
							if(numBitsToRead == 0)
							{
								printf("End of decoding\n");
								fclose(decodedFile);
								fclose(fin);
								return;
							}
						}
				}
			}
		}
		
		fclose(fin);
	}
	else
	{
		printf("Unable to open %s \n",fName);
		return;
	}
}
