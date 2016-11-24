//seungbin write this code

int countNonZeroCharacters(void)
{
	int cnt = 0;
	for (int i = 0; i < num_ASCII; i++)
	{
		if(charFreq[i]>0)
		{
			cnt++;
		}
	}
	return cnt;
}
