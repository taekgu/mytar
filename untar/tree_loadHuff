void tree_loadHuff(huffNode* head, FILE* hufFile)
{
	//input data
	int data;

	//read file and make tree
	while(fscanf(hufFile,"%d:",&data) != EOF)
	{
		//node go head
		huffNode* node = head;

		while(1)
		{
			int i = fgetc(hufFile);

			//one string end
			if(i == '\n')
			{
				//input data current node
				node->value = data;
				break;
			}
			//if number,go that node
			else
			{
				//if left node
				if(i == 48)//at ascii 0 = 48
				{	
					//left node x,make left node
					if(node->left == NULL)
					{
						node->left = (huffNode*)malloc(sizeof(huffNode));
						node->left->left = NULL;
						node->left->right = NULL;
					}
					node = node->left;
				}
				//if right node
				else
				{
					//right node x,make right node
					if(node->right == NULL)
					{
						node->right = (huffNode*)malloc(sizeof(huffNode));
						node->right->left = NULL;
						node->right->right = NULL;
					}
					node = node->right;
				}
			}
		}
	}
}

