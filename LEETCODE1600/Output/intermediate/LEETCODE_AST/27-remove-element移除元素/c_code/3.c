int removeElement(int* nums, int numsSize, int val){
    int count=0;
    int *p=nums;
    for(int i=0;i<numsSize;i++){
        if(p[i]!=val){
            *nums=p[i];
            nums++;
            count++;
        }
    }
    return count;
}