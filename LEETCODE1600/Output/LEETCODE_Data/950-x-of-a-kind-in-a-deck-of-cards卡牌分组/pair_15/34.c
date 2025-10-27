int gcd(int a, int b)
{
	int c = 0;
	
	while(b)
	{
		c = a%b;
		a = b;
		b = c;
	}
	
	return a;
}
 
bool hasGroupsSizeX(int* deck, int deckSize)
{
	if(deckSize == 1 || deckSize == 0)
	return false;
	
	int a[10000] = {0}, m = 0, gcd_ = 0;
	
	for(int i = 0; i < deckSize; i++)
	a[deck[i]]++;
	
	gcd_ = a[deck[0]];
	for(int i = 0; i < 10000; i++)
	{
		if(a[i])
		{
			gcd_ = gcd(gcd_, a[i]);
			
			if(gcd_ < 2)
			return false;
		}
	}

	return true;
}