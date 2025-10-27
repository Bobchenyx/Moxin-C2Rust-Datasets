int* grayCode(int n, int* returnSize){
    int num = 1 << n;
    int *a = malloc(sizeof(int) * num);
    for(int i = 0;i < num;i++)
        a[i] = (i >> 1) ^ i;
    *returnSize = num;
    return a;
}