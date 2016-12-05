#include "head.h"

int main(int argc, char* argv[])
{
	lastHeapIdx = 0;
	codeBufIdx = -1;
	if (argc < 3 && argc > 4)
	{
		printf("please again check!\n");
		return -1;
	}

	if(argc == 4)
	{
		if(strcmp(argv[3], "-v") == 0)
	        {
        	        if(strcmp(argv[1],"-e") == 0)
                	{
                       		// huffman incoding -> sb
	                       	printf("Start Huffman Encoding to visible\n");
        	               	performEncoding(argv[2]);
                	}else if(strcmp(argv[1], "-d") == 0)
	                {
        	                // huffman decoding -> jk
                	       	printf("Start Huffman Decoding to visible\n");
                       		writeData(argv[2]);
                	}else
                	{
                        	printf("please again check!!\n");
                        	return -1;
                	}
        	}else
        	{
                	printf("please again check option!!!\n");
        	}
	}
	else
	{
		if(strcmp(argv[1],"-e") == 0)
		{
                        // huffman incoding -> sb
                        printf("Start Huffman Encoding\n");
                        performEncoding_n(argv[2]);
                }else if(strcmp(argv[1], "-d") == 0)
                {
                        // huffman decoding -> jk
                        printf("Start Huffman Decoding\n");
                        //writeData_n(argv[2]);
                }else
                {
                        printf("please again check!!\n");
                        return -1;
                }
	}
	return 0;
}
