static int sum;

int sumNums(int n)
{   
    sum=((sum!=0)&(sum==0));
    n>0&&sumNums(n-1);
    sum+=n;
    return sum; 
}