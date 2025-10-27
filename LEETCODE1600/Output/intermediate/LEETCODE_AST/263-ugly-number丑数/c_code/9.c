bool isUgly(int num){
    if(num < 1)
        return false;
    int i;
    while(num != 1){
        if(0 == num%2)
            num /= 2;
        else if(0 == num%3)
            num /= 3;
        else if(0 == num%5)
            num /= 5;
        else 
            return false;
    }
    return true;
}