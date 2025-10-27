bool isPalindrome(int x){
    int num[32] = { 0 };
    int r = 0, k = 0;
    if(x < 0) return false;
    
    while(x){
        r = x % 10;
        num[k++] = r;
        x /= 10;
    }

    for(int i = 0, j = k - 1; i < j; i++, j--){
        if(num[i] != num[j]){
            return false;
        }
    }
    return true;
}