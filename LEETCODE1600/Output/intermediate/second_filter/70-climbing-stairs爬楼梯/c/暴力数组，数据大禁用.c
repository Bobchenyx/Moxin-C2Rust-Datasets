int climbStairs(int n)
{
int num[100]={0};num[0]=1,num[1]=2;

int i;
if(n==0||n==0)
return 1;
else if(n==2)
return 2;
else
{
for(i=2;i<n;i++)
num[i]=num[i-1]+num[i-2];
return num[n-1];
}
}