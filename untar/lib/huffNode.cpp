typedef struct huffNode
{
	short value; //
	int freq; //frequency
	struct huffNode* left; //left node
	struct huffNode* right; //right node
}huffNode;
