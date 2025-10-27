int reverse(int x){
	//2^31=2147483648
	int MAX=-214748364;
	int res=0,sign=1;
	if(x>0){
		sign=0;
		x=-x;
	}
	while(x<0){
		if(res>MAX){
			res=res*10+x%10;
			x/=10;
		}
		else if(res<MAX)return 0;
		else if(x<8){
			res=res*10+x%10;
			x/=10;		
		}else return 0;
	}
    if(sign==1)	return res;
    else return -res;
}