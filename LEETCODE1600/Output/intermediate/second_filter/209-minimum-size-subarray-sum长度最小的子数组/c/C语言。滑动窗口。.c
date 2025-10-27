#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minSubArrayLen(int s, int* nums, int numsSize){
    int i = 0, j = 0, sum = 0, min = 0;
    while(true){
        if(sum < s){
            if(j == numsSize){
                break;
            }
            sum += nums[j++];
        }else{
            if(min == 0){
                min = j - i;
            }
            min = MIN(min, j - i);
            if(min == 1){
                return min;
            }
            sum -= nums[i++];
        }
    }
    return min;
}