int trailingZeroes(int n){
    int numoffive = 0,temp;
    for(n = (n / 5) * 5;n > 0;n -= 5){
        temp = n;
        while(temp % 5 == 0){
            temp /= 5;
            numoffive++;
        }
    }
    return numoffive;
}