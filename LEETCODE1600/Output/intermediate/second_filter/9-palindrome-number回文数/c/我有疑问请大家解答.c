bool isPalindrome(int x)
{
    int n;
    int s;
    s=x;
    double new_num;
    new_num=0;
    while(s!=0)
    {   
        n=s%10;
        new_num=n+new_num*10;
        s=s/10;
    }
 if(new_num==x && x>0 ||x==0)
    return true;
 else
    return false;
}