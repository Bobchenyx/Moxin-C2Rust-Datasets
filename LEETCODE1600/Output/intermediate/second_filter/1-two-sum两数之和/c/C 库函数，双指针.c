struct NODE
{
    int val;
    int pos;
};

int cpr(const void* a, const void* b){
    return ((struct NODE*)a)->val - ((struct NODE*)b)->val;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
//double-point
    int head = 0;
    int tail = numsSize -  1;
    int sum = 0;
    struct NODE* numNode = NULL;
    int *result = NULL;
    result = (int*)malloc(sizeof(int) * 2);
    numNode = (struct NODE*)malloc(sizeof(struct NODE) * numsSize);

    for(int i = 0; i < numsSize; i++){
        numNode[i].val = nums[i];
        numNode[i].pos = i;
    }
    //rise sort
    qsort(numNode, numsSize, sizeof(struct NODE), cpr);

    while(head < tail){
        sum = numNode[head].val + numNode[tail].val;
        if(sum > target){
            tail--;
        }else
        if(sum < target){
            head++;
        }else{
            result[0] = numNode[head].pos;
            result[1] = numNode[tail].pos;
            break;
        }
    }
    free(numNode);
    *returnSize = 2;
    return result;
}