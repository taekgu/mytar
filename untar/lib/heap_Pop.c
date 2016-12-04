#include "head.h"

huffNode* heap_Pop(huffNode** head)
{
        //huffnode ju.
        huffNode* newhn = (huffNode*)malloc(sizeof(huffNode));
        newhn->value = head[0]->value;
        newhn->freq = head[0]->freq; //top node is min.
        newhn->left = head[0]->left;
        newhn->right = head[0]->right;

        //if node > 2 remain
        if(heapCnt > 1)
        {
                //last node copy to first node & del
                head[0]->value = head[heapCnt-1]->value;
                head[0]->freq = head[heapCnt-1]->freq;
                head[0]->left = head[heapCnt-1]->left;
                head[0]->right = head[heapCnt-1]->right;
                free(head[heapCnt-1]);
                head[--heapCnt] = NULL; //heap -- & NULL

                //MinHeapify
                heap_MinHeapify(head, 1);
        }
        //if node < 1
        else
        {
                free(head[0]);
                head[0] = NULL;
                heapCnt--; //heap --
        }

        return newhn;
}




