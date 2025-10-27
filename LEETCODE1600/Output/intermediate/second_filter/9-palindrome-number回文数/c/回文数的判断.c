bool isPalindrome(int x){ 
    char num[10];
    char cnt = 0;
    char i;

    if (x < 0)
        return false;
 
    while (x > 0)
    {   
        num[cnt++] = x % 10; 
        x /= 10; 
    }   

    for (i = 0; i < cnt / 2; i++)
    {   
        if (num[i] != num[cnt - i - 1]) 
            return false;
    }   

    return true;
}