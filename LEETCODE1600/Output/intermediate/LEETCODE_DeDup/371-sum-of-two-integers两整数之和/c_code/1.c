int getSum(int a, int b){
static int sum,k;
sum=a^b;
k=(unsigned int)(a&b)<<1;
if(k==0) return sum;
else return getSum(sum,k);
}