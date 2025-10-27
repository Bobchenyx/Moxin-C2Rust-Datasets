bool isPalindrome(int x){
    if(x<0)
        return false;
    if(x<10)
        return true;

    
    int  nums[30];
    int i=0;
    int p=x;
    while(p!=0)
    {
        int pop =p%10;
        nums[i++] = pop;
        p/=10;
    }
    //nums[i]为空，之前有数。
    //两个指针，依次往中间靠拢，比对是否相同。
    int j;
    for( j=0,--i;  j<i;   j++,i--)
    {
        if(nums[j]!=nums[i]) 
            return false;
    }
    return true;

}