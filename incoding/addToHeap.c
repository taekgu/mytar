#include "head.h"

void addToHeap(struct node *cur)
{
	lastHeapIdx++;
	heap[lastHeapIdx] = cur;
	
	int currentIdx = lastHeapIdx;
	int parentIdx = lastHeapIdx/2;

	while(parentIdx >= 1)
	{
		if(heap[parentIdx]->frequency > heap[currentIdx]->frequency)
		{
			struct node * temp = heap[parentIdx];
			heap[parentIdx] = heap[currentIdx];
			heap[currentIdx] = temp;

			currentIdx = parentIdx;
			parentIdx = currentIdx/2;
		}
		else
		{
			break;
		}
	}
}
