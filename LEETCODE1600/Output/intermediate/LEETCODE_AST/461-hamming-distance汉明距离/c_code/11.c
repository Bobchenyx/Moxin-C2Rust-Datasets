int hammingDistance(int x, int y){
    int n = 0, temp = 0;
    int count = 0;
    n = x ^ y;
    while(n)
    {
        if(temp = n & 0x00000001)
            count += 1;
        n >>= 1;
    }
    return count;
}