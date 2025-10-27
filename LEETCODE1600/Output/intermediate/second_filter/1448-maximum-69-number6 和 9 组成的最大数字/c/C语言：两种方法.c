int maximum69Number (int num){
    int m = 1000;
    int t = num;
    while (m){
        int n = t / m;
        if (n == 6){
            return num + 3 * m;
        }
        if (n != 0)
            t -= 9 * m;
        m /= 10;
    }
    return num;
}