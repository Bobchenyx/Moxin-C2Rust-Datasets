int climbStairs(int n){
    if(n==0){return 0;}
	if(n==1){return 1;}
    if(n==2){return 2;}
	int a=1;int b=2;int c=0;
	n=n-2;
	while(n--){
		c=a+b;
		a=b;
		b=c;
	}
	return c;
}