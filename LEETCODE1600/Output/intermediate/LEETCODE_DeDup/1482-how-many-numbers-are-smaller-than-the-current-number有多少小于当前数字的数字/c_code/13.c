//Note: The returned array must be malloced, assume caller calls free().
int *smallerNumbersThanCurrent(int *nums, int numsSize, int *returnSize)
{
    //以nums = [8,1,2,2,3]为例
    int max = 101;
    int *ans = malloc(numsSize*sizeof(int));
    *returnSize =numsSize;//被这个坑了，我还以为要把结果存到这里面去，其实是存放结果数组的大小
    int hash[101] = {0}, rank[101] = {0};//hash代表每个数字有多少个，rank代表数字在数组的大致排名
    
    //hash=[1,3,3,1,0,0,0,1,1...]
    for (int i = 0; i < numsSize; i++)//扫描数组统计各数字个数
        hash[*(nums + i)]++;

    //计算各数字的大致排名
    //rank = [1,3,4,4,4,4,4,5,5,5...]
    rank[0]=hash[0];
    for (int i = 1; i < max; i++)
        rank[i] = hash[i] + rank[i - 1];

    //计算所求数字的精确排名
    //ans=[rank[8]-hash[8]...],即第一个数字8的最大排名减去数字8的个数
    //rank[8]=5,hash[8]=1,排名第5，一共有1个8，得小于8的有4个
    //nums = [8,1,2,2,3]
    for (int i = 0; i < numsSize; i++)
        *(ans + i) = rank[*(nums + i)] - hash[*(nums + i)];

    return ans;//返回答案数组
}