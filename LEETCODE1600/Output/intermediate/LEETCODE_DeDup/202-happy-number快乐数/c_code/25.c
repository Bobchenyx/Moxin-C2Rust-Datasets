bool isHappyCore(int n, int* map);

bool isHappy(int n){
	
	int map[243] = {0};
	return isHappyCore(n, map);
}

bool isHappyCore(int n, int* map)
{
	if(n == 1) 
	{
		return true;
	}
	
	if(n <= 243) // 小于等于243
	{
		if(map[n - 1] == 1)
		{
			return false;
		}
		else
		{
			map[n - 1] = 1;
		}
	}
	
	int next = 0;
	
	while(n > 0)
	{
		next += (n % 10) * (n % 10);
		n /= 10;
	}
	
	return isHappyCore(next, map);
}