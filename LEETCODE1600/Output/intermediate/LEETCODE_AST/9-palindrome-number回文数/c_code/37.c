bool isPalindrome( int x )
{
    if(x<0){
        return false;
    }
    if(x/10==0){
        return true;
    }
	if(x%10==0){
		return false;
	}
	int num=0,inc=1;
	while(num<x){
		num=num*10+x%10;
		x/=10;
		inc*=10;
	}
	if(num==x){
		return true;
	}else if(x/(inc/10)){
		return false;
	}else{
		if(x/(inc/100)){
			if(num/10==x){
				return true;
			}else{
				return false;
			}
		}else{
		    return false;
		}
	}
}