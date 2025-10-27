int comp(const void *a, const void *b)
{
	return *(int*)a-*(int*)b;
}  

int minIncrementForUnique(int* A, int ASize){
	qsort(A,ASize,sizeof(int),comp);
	int count=0;
	for(int i=0;i<ASize-1;i++)
	{
		if(A[i+1]<=A[i])
		{
			count+=A[i]-A[i+1]+1;
			A[i+1]=A[i]+1;
		}
	}
	return count;
}