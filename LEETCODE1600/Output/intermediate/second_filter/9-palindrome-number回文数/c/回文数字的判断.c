bool isPalindrome(int x)
{
    int revnum;
    if(x<0||(x%10==0&&x>0))  \\少了这个判断，后边的算法就会出错，具体可以通过输入10来观察结果
    return 0;
    for(revnum=0;x>revnum;x=x/10)
    {
        revnum=revnum*10+x%10;
    }
    if(revnum==x||x==revnum/10)
    return 1;
    else
    return 0;
}