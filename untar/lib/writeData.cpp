#include "head.h"

unsigned int wbData = 0;
int remBit = 0;

void writeData(huffNode* head, FILE* in, FILE* out)
{
        //if not unsigned = (first bit = 1)
        unsigned char ch[1];
        //node = head
        huffNode* node = head;

        while(fread(ch,sizeof(char),1,in))
        {
                //accumulate
                wbData = (wbData << 8) + ch[0];
                remBit += 8;

                //reset node
                node = head;

                //if last bit > 1
                for(int i=remBit-1; i >= 0; i--)
                {
                        //node move
                        if(((wbData >> i) & 1) == 0)
                                node = node->left;
                        else
                                node = node->right;

                        if(node->left == NULL) //cur node == leaf
                        {
                                //if quit char,quit
                                if(node->value == 256)
                                        return;

                                //buffer
                                char temp[1] = {node->value};
                                //record result
                                fwrite(temp,sizeof(char),1,out);
                                //remain bit = i
                                remBit = i;

                                //reset node
                                node = head;
                        }
                }
        }
}

