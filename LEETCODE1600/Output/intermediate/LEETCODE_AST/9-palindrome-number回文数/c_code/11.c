bool isPalindrome(int x){
    if(x<0)
        return false;
    long int ux=0,a=x;
    int i;
    while(a/10)
    {
       ux*=10;
       ux+=a%10;
       a/=10;
    }
	ux*=10;
    ux+=a%10;
    if(x==ux) return true;
    else return false;
}