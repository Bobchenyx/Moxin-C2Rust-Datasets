bool isPalindrome(int x){
    if(x<0) return false;
    long m=0;
    int n=x;
    while(n){
        m=m*10+n%10;
        n/=10;
    }
    return m==x;
}