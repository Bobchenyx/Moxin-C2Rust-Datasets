int subtractProductAndSum(int n){
    int count = 0,a,b,i,j,multiply = 1,sum = 0,temp;
    j = n;
	while(j != 0)
    {
        j/=10;
        ++count;
    }
		for(i = 0,a = 0,b = 0,temp = 1;i < count;i++){
			a = n/temp;
            b = a%10;
            sum += b;
            temp *= 10;
        }
    
        for(i = 0,a = 0,b = 0,temp = 1;i < count;i++){

            a = n/temp;
            b = a%10;
            multiply *= b;
            temp *= 10;
        }
	return multiply-sum;
}