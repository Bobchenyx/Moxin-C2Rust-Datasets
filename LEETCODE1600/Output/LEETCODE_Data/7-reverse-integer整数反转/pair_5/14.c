int reverse(int x){
    long result = 0;
    if(!(-2147483648 < x < 2147483647)) return 0;
    while(x!=0){
        result = result * 10 + x % 10;  
        x = x / 10;
      
    }  
    if(-2147483648 > result || result > 2147483647)                                return 0;
    else return result;
}