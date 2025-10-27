int removeElement(int* nums, int numsSize, int val){
    int i=0;int j=0;int jump=0;
    while(i<numsSize){
        if(nums[i]==val){
            int k;
            for(k=i;k<numsSize;k++){
                if(val==nums[k]){
                    i++;
                    jump++;
                }else{
                    break;
                }
            }
        }
        if(j>=numsSize||i>=numsSize){
            break;
        }
        nums[j]=nums[i];
        j++;i++;
    }
    return numsSize-jump;
}