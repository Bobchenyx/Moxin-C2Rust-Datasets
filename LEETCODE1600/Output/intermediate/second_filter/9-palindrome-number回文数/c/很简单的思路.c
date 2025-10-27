bool isPalindrome(int x){
    long a = x,count = 0;
    if(x < 0)
        return false;
    while(x){
        count = count*10 + x%10;
        x = x/10;
    }
    if(count == a){
        return true;
    }
    return false;
}