int getSum(int a, int b){
    int low;
    unsigned int carry;

    while (true) {
        low = a ^ b;
        carry = a & b;
        if(carry == 0) break;
        //printf("low=0x%x carry=0x%x a=0x%x, b=0x%x\n", low, carry, a, b);
        a = low;
        b = (carry << 1);
    }

    return low;
}