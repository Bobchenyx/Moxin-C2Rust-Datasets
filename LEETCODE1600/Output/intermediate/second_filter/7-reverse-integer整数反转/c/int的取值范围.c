int reverse(int x){
    
    int r = 0;
    long long sum = 0;
    while(x != 0){
        r = x % 10;
        x = x / 10;
        sum = sum * 10 + r; 
    }
    if(sum > INT_MAX || sum < INT_MIN) return 0;
    else return sum;
}