#include "head.h"

int main(int argc, char* argv[])
{
	lastHeapIdx = 0;
	codeBufIdx = -1;
	if (argc < 3)
	{
		printf("please again check!\n");
		return -1;
	}

	if(strcmp(argv[1],"-e") == 0)
	{
		// huffman incoding -> sb
		printf("Start Huffman Encoding\n");
		performEncoding(argv[2]);
	}else if(strcmp(argv[1], "-d") == 0)
	{
		// huffman decoding -> jk
		printf("Start Huffman Decoding\n");
	}else
	{
		printf("please again check!!\n");
		return -1;
	}

	return 0;
}
