int* sortedSquares(int* a, int n, int* returnSize){
	*returnSize=n;
	if(n==0) return a;
	a[0]=a[0]*a[0];
	int j;
	for(int i=1;i<n;i++){
		int temp=a[i]*a[i];
		for(j=i-1;j>=0;j--){
			if(temp<a[j]) a[j+1]=a[j];
			else break;
		}
		a[j+1]=temp;
	}
	return a;
}