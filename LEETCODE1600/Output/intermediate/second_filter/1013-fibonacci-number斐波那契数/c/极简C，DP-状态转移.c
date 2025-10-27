int fib(int N){
    int y=0, x=1, temp;
    for (int i=0; i++<N;) {
        temp = y;
        y = temp + x;
        x = temp;
    }
    return y;
}