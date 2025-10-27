int divide(int dividend, int divisor){
int fu_value(long int a);//将所有数值转为负数
	int flag_judge(long int a);

	long int dividend_1, divisor_1,temp;
    dividend_1=dividend;divisor_1=divisor;
	
	int f1, f2, flag,num=0,i=0;
	long int answer = 0;
	f1 = flag_judge(dividend_1);
	f2 = flag_judge(divisor_1); 
	flag = f1 ^ f2; 
	dividend_1 = fu_value(dividend_1);
	divisor_1 = fu_value(divisor_1); 
	temp = dividend_1;
	
    if (divisor_1 == -1)
	{
		answer = dividend_1;
		if ((answer == -2147483648) && (f2)) { answer = -2147483647; }
	}
	else {
		if (dividend_1 != divisor_1)
		{
			while (temp-divisor_1-divisor_1<=0)
			{
				
				temp = temp - divisor_1 - divisor_1; 
				answer = answer + 2; 
			while (temp - divisor_1 <= 0)
			{
				temp = temp - divisor_1;
				answer = answer + 1;
			}

			
		}
		else { answer = 1; }
		answer = fu_value(answer);
		
	}
	//对answer做处理
		if (flag==0)//结果为负数
		{
			answer = 0 - answer; 
			
		}
        
	printf("answer: %ld\n", answer);
    return answer;
}
int flag_judge(long int a)
{
	int f;
	if (a < 0)
	{
		f =1;
	}
	else
	{
		f = 0;
	}
	return f;
}
int fu_value(long int a)
{
	if (a > 0)
	{
		a = 0 - a;//转为负数
	}return a;
}