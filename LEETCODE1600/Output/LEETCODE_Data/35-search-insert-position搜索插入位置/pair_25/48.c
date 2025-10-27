int BinaSearch(int *A,int lo,int hi,int e){
	while(lo<hi){
		int mid=(lo+hi)>>1;
		If(e<A[mid])
			hi=mid;
		else if(A[mid]<e)
			lo=mid;
		else
			return mid	
	}
	return -1;
}