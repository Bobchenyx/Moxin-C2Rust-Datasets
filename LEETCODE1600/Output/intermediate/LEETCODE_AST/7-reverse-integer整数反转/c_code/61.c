int reverse(int x){
    long rNum = 0;
    while(x != 0){
        rNum = rNum * 10 + x % 10;
        x = x / 10;
    }
    if((int) rNum != rNum) return 0;
    return rNum;
}