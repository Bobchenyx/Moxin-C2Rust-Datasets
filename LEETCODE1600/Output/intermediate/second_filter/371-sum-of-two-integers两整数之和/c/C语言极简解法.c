int getSum(int a, int b)
{
    int sum = a ^ b;
    unsigned int carry = (unsigned int)(a & b) << 1;
    if (carry != 0) {
        sum = getSum(sum, (int)carry);
    }
    return sum;
}