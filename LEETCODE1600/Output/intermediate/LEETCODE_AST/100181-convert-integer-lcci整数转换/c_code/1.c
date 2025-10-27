int convertInteger(int A, int B){
    unsigned int c=(unsigned int)A^(unsigned int)B;
    int sum=0;
    while(c>0){
        sum+=(c%2);
        c=c>>1;
    }
    return sum;
}