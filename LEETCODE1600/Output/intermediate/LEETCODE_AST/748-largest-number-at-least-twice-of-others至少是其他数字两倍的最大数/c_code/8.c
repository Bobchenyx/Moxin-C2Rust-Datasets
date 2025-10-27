int cmp(const int *a,const int *b) {
    return -(*(int *)a - *(int *)b);
}
int dominantIndex(int* nums, int numsSize){
    if(numsSize == 0) {
        return -1;
    }
    if(numsSize == 1){
        return 0;
    }
    int *sort = (int*)malloc(numsSize*sizeof(int));
    for(int i = 0;i<numsSize;i++) {
        sort[i] = nums[i];
    }
    qsort(sort,numsSize,sizeof(int),cmp);
    if(sort[0] >= 2*sort[1]) {
        for(int i = 0;i <numsSize;i++) {
            if(nums[i] == sort[0]) {
                return i;
            }
        }
    }
    return -1;

}