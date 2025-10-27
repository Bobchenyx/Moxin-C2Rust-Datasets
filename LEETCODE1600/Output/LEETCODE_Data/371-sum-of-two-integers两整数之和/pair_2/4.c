int getSum(int a, int b){
    int sum = a ^ b;
    unsigned int carry = (unsigned int) (a&b)<<1;
    return carry ? getSum(sum,carry) : sum;
}