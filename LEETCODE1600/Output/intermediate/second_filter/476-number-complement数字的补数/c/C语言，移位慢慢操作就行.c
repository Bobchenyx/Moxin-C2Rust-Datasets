int findComplement(int num){
    int res = 0;
    int tmp = 0;
    int idx = 0;
    while(num)
    {
        tmp = (~num) & 0x01;
        num = num >> 1;

        res += tmp << idx;
        idx++;
    }
    return res;
}