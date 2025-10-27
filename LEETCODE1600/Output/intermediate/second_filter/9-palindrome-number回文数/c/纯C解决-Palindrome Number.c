bool isPalindrome(int x){
    if(x<0)
    return false;
    long rev_x=0;
    int temp=x;
    while(temp)//翻转
    {
        rev_x=rev_x*10+temp%10;
        temp/=10;
        if(rev_x>x)
        return false;
    }

    if(rev_x==x)
    return true;
    return false;
}