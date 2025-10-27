//递归
int getSum(int a, int b){
    if(b == 0) return a;
    int carry = ((unsigned int)(a & b)) << 1;
    int sum = a ^ b;
    return getSum(sum, carry);
}

//迭代
int getSum(int a, int b){
    int tmp = 0;
    while(b != 0) {
        tmp = ((unsigned int)(a & b)) << 1;
        a = a ^ b;
        b = tmp;
    }

    return a;
}