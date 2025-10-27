int mySqrt(int x){
    for (int i = 0; (long)i * i <= x; i++);
    return i - 1;
}