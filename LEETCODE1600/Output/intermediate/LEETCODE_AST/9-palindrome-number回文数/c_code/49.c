bool isPalindrome(int x){
if(x<0) return false;
else 
{
    long i=0,k,j;
    for(k=x;k!=0;k=k/10)
    {
        j=k%10;
        i=i*10+j;

    }
    if(i==x)
   return true;
    else return false;
}
}