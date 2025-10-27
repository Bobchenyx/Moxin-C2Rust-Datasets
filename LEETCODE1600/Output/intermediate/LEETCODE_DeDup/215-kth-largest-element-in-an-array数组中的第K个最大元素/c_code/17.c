void Heap(int a[],int pos,int length){
	int temp=a[pos];
	for(int i=2*pos+1;i<length;pos=i,i=2*i+1){
		if((i+1)<length&&a[i]>a[i+1])i++;
		if(temp>a[i])
			a[pos]=a[i];
		else break;
	}
	a[pos]=temp;	
}
int findKthLargest(int* a, int numsSize, int k){
	for(int i=k/2-1;i>=0;i--)
		Heap(a,i,k);
	for(int i=k;i<numsSize;i++){
		if(a[0]<a[i])    
            a[0]=a[i];
		Heap(a,0,k);
	}
	return a[0];
}