#define buf_SZ 100

// Lee Seung Bin write this code 
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
	
	while(fgets(buf, buf_SZ, fin) != 0)
	{
		int len = strlen(buf);
		for( int i = 0;  i < len; i++)
		{
			
		}
	}

	fclose(fin);
}
