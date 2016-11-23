// seungbin write code
void showCharFrequency(void)
{
	for (int i = 0; i<num_ASCII; i++)
	{
		if(charFreq[i] > 0)
		{
			printf("ASCII code %d ( %c ) : %d \n", i, (char)i, charFreq[i]);

		}
	}
}
