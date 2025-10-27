int wiggleMaxLength(int* nums, int numsSize){
    int i,j;
    int n,nn;

    if (1 >= numsSize){
        return numsSize;
    }

    if (2 == numsSize){
        if (nums[0] == nums[1]){
            return 1;
        }
        else{
            return 2;
        }
    }

    if (3 == numsSize){
        if (nums[0] < nums[1]){
            return (nums[1] > nums[2] ? 3 : 2);
        }
        else if (nums[0] > nums[1]){
            return (nums[1] < nums[2] ? 3 : 2);
        }
        else{
            return (nums[1] == nums[2] ? 1 : 2);
        }
    }

    j = wiggleMaxLength(nums + 1, numsSize - 1);
    //printf(" j=%d nums[0]=%d ",j,nums[0]);
    for (i = 1; i < numsSize - 2; i++){
        if (nums[i] == nums[i + 1]){
            continue;
        }
        else{
            break;
        }
    }

    n = nums[i];
    nn = nums[i + 1];

    if (1 == j){
        j += 1;
    }
    else{
        if (((nums[0] < n) && (n > nn)) || 
        (((nums[0] > n) && (n < nn)))){
            j += 1;
        }
    }

    return j;
}