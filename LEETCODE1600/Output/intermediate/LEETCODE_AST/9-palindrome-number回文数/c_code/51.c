int reverse(int x){
    long res = 0;
    while(x) {
         res = res * 10 + x % 10;
         x /= 10;
     }
     if(res != (int)res) return 0;
     return res;
}
bool isPalindrome(int x){
    if(x<0) return false;
    if(x==reverse(x)) return true;
    return false;
}