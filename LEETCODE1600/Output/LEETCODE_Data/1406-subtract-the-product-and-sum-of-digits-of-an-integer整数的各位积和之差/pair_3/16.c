int subtractProductAndSum(int n)
{
    if (n <= 0) {
        return 0;
    }

    int temp[10] = {0};
    int len = 0;
    int mul = 1;
    int sum = 0;

    while (n) {
        temp[len++] = n % 10; 
        n = n / 10;
    }
    for (int i = 0; i < len; i++) {
        mul *= temp[i];
        sum += temp[i];
    }
    return mul - sum;
}