int compare(const void *a, const void *b){
    int *pa = (int*)a;
    int *pb = (int*)b;
    return (*pa)- (*pb);  
//or return *(int *)a - *(int *)b; //均为从小到大排序
}

int majorityElement(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), compare);
    return nums[numsSize/2];
}