c []
int hammingDistance(int x, int y){
int a;
a=x^y;  
int res=0;
while(a>0)
{
    if(a%2!=0) res++;     //判断二进制最后一位是否为1
    a=a/2;                //二进制右移1
}
return(res);
}