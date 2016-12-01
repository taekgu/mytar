#include "head.h"

struct node* deleteFromHeap()
{
	struct node* retVal = heap[1];
	int parent = 1;
        int left = 2*parent;
        int right = left+1;

	if(lastHeapIdx <= 0)
	{
		printf("Heap is empty\n");
		return 0;
	}
	
	heap[1] = heap[lastHeapIdx];
	lastHeapIdx--;

	while(1)
	{
		if(left > lastHeapIdx)
		{
			break;
		}else if(right > lastHeapIdx){
			if(heap[left]->frequency < heap[parent]->frequency)
			{
				struct node * temp = heap[left];
				heap[left] = heap[parent];
				heap[parent] = temp;

				parent = left;
				left = 2*parent;
				right = left + 1;
			}else {
				break;
			}
		}else {
			int smaller;
			if(heap[left]->frequency <= heap[right]->frequency)
			{
				smaller = left;
				
			}else {
				smaller = right;
			}
			if(heap[left]->frequency < heap[parent]->frequency)
                        {
                                struct node * temp = heap[smaller];
                                heap[smaller] = heap[parent];
                                heap[parent] = temp;

                                parent = smaller;
                                left = 2*parent;
                                right = left + 1;
                        }else {
                                break;
                        }

		}
	}

	return retVal;
}
