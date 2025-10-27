bool isPalindrome(int x){
    if(x<0)
        return false;
    if(x>0&&x<10)
        return true;
    if(x>1000000000&&x%10>2)
        return false;

    int temp=x;
    int y=0;
    int  s=10;
    while(temp!=0)
    {
        y=y*s+temp%s;
        temp=temp/s;
    }
   if(x==y) 
        return true;
    else 
        return false;


}