int factorial(int n)
{
    int num = 1;
    while (n > 0)
    {
        num *= n;
        n--;
    }
    return num;
}
void deleteItem(int *nums, int numsSize, int in)
{
    for (; in < numsSize - 1; in++)
        nums[in] = nums[in + 1];
}
char *getPermutation(int n, int k)
{
    int i, j = 0, nums[n], factor;
    char *res = (char *)malloc(sizeof(char) * 10);
    for (i = 1; i <= n; i++) //初始化一个 1-n的数组
        nums[i - 1] = i;
    for (i = 0,k--; i < n; i++) //k要先减去1
    {
        factor = factorial(n - i - 1);
        res[j++] = nums[k / factor] + '0';
        deleteItem(nums, n - i, k / factor); //取出一个元素
        k %= factor;
    }
    res[j] = '\0';
    return res;
}