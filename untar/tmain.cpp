#include "head.h"

int tmain(int argc, char * argv[])
{
        char fileName[100];
        FILE *inputFile; //from tar
        FILE *outputFile; //to tar
        FILE *hufFile; //huffmanfile
        //variable
        printf("please input a filename that you want tar(ex:exam.txt.cmp):");
        scanf("%s",&fileName);
        inputFile = fopen(fileName,"rb");

        //from tar file exist?
        if(inputFile == NULL)
        {
                printf("file is not open.\n");
                system("pause");
                return -1;
        }

        outputFile = fopen(strcat(fileName,".ucp"),"wb");

        //make huffman file name
        int pos = 0;
        while(fileName[pos] != '\0')
                pos++;
        fileName[pos-7] = 'h';
        fileName[pos-6] = 'u';
        fileName[pos-5] = 'f';
        fileName[pos-4] = '\0';
        hufFile = fopen(fileName,"r");

        //open to tar file? 
        if(outputFile == NULL || hufFile == NULL)
        {
                printf("file is not open.\n");
                system("pause");
                return -1;
        }

        //tree make node
        huffNode* huff = (huffNode*)malloc(sizeof(huffNode));
        huff->right = NULL;
        huff->left = NULL;

        //make tree
        tree_loadHuff(huff,hufFile);

        //make original file
        writeData(huff,inputFile,outputFile);

        //message output
        printf("file tar compeletly.\n");
        system("pause");
        return 0;
}
