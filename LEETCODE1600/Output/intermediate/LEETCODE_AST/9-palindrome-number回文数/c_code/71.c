bool isPalindrome(int x){
    if(x<0)
        return 0;
    int a[10],i=0,j=0;
	for(;x;a[i]=x%10,i++,x=x/10);
	for(i--;j<=i;j++,i--){
		if(a[j]!=a[i])
			return 0;
	}
	return 1;
}