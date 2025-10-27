bool isPalindrome(int x){
    if (x >= 0 && x/10 == 0)
        return true;
    if (x < 0 || x%10 == 0)
        return false;
    long rev = 0, copyx = x;
    while (x) {
        rev = rev*10 + x%10;
        x/=10;
    }
    if (rev == copyx) return true;
    return false;
}