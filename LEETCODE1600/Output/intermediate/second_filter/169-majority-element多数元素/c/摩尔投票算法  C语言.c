int majorityElement(int* nums, int numsSize){
    int i;
    int team,count=1;
    team=nums[0];
    for(i=1;i<numsSize;i++){
        if(nums[i]==team) count++;
        else if(count>1) count--;
        else{
            team=nums[i];
            count=1;
        }
    }
    return team;
}