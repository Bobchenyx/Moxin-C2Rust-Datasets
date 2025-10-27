int getSum(int a, int b)
{
	
	int sum=a;
	unsigned int carry=b;
	while(carry)
	{
		int temp=sum;
		sum=temp^carry;
		carry=(temp&carry)<<1;

	}
	return sum;
}