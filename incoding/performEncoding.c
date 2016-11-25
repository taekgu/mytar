
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
		for( int i = 0;  i < len; i++)
		{
			charFreq[(int)buf[i]]++;
		}
	}
	
	showCharFrequency();
	
	int cnt = countNonZeroCharacters();
	heap = (struct node **)malloc((cnt+1)*sizeof(struct node *));
	memset(heap, 0, (cnt+1)*sizeof(struct node*));
	
	for(int i = 0; i< num_ASCII; i++)
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

	struct node *temp = deleteFromHeap();
	printf("previous root %d (%c) : %d\n", (int)temp->c, temp->c, temp-<frequency);
	printf("root %d (%c) : %d\n", (int)heap[1]->c, heap[1]->c, heap[1]->frequency);

	fclose(fin);
}
