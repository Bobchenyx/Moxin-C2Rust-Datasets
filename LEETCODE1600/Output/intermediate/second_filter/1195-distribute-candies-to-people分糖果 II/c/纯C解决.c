/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    *returnSize=num_people;
    int *nums=(int *)malloc(sizeof(int)*num_people);
    memset(nums,0,sizeof(int)*num_people);
    int index=-1;

    int i=1;
    while(candies-i>=0)
    {
        ++index;
        index%=num_people;
        nums[index]=i+nums[index];
        candies-=i;
        i++;
    }
    ++index;
    index%=num_people;
    nums[index]=candies+nums[index];
    return nums;
}