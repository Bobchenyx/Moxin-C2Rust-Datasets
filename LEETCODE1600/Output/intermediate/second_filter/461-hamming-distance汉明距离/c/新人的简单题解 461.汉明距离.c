int hammingDistance(int x, int y){
    int k=x^y;
    int res=0;
    for(int i=0;i<32;i++)
    {
        res+=(k&1);
        k>>=1;
    }
    return res;
}