int reverse(int x){
    long res = 0;
    while(x) {
         res = res * 10 + x % 10;
         x /= 10;
     }
     if(res != (int)res) return 0;
     return res;
}