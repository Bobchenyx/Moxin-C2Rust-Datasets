int compare(const void*, const void*);

int findContentChildren(int* g, int gSize, int* s, int sSize){
	
	qsort(g, gSize, sizeof(int), compare);
	qsort(s, sSize, sizeof(int), compare);
	
	int i = gSize - 1, j = sSize - 1, count = 0;
	
	while( i >= 0 && j >= 0)
	{
		if(s[j]>=g[i])
		{
			i--;
			j--;
			count++;
		}
		else
		{
			i--;
		}
	}
	
	return count;
	
}

int compare(const void* x, const void* y)
{
	return (*(int*)x - *(int*)y);
}