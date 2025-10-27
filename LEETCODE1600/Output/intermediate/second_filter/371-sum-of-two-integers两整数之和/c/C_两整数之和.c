int getSum(int a, int b){
    int sum = a ^ b;
    unsigned carry = (unsigned) (a&b)<<1;
    return carry ? getSum(sum,carry) : sum;
}