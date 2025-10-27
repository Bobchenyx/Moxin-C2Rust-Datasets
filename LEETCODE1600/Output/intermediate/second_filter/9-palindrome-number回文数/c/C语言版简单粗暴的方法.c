bool isPalindrome(int x){

    long rev = 0;
    int obv = x;
    int num = 0;

    while(x)
    {
        num = x%10;
        rev = rev*10 + num;
        x = x/10;
    }

    if(rev < 0) return false;
    else
    {
        if(rev == obv) return true;
        else return false;
    }


}