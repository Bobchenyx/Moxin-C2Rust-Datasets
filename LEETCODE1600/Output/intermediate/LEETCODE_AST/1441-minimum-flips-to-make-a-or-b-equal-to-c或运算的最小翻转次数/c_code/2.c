int minFlips(int a, int b, int c){
    int aBit=0,bBit,cBit;
    int i=0,sum=0;

    for(i=0;i<32;i++){
        aBit = (a>>i) & 0x1;
        bBit = (b>>i) & 0x1;
        cBit = (c>>i) & 0x1;
        if((aBit||bBit) != cBit)
            sum += abs(aBit + bBit - cBit);
    }
    return sum;
}