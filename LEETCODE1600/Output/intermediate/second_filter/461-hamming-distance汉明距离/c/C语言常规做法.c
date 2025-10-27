int hammingDistance(int x, int y){
    int xor,res=0;
    xor=x^y;
    while(xor!=0){
        if(xor%2!=0) res++;
        xor=xor/2;
    }
    return res;
}