bool checkPossibility(int* nums, int numsSize){
    int i = 0;
    int j = 0;
    int count = 0;
    int hi = 0;
    int low = 0;
    bool ret = false;

    if(numsSize <= 2) {
        return true;
    }
    
    for(i = 0; i + 1 < numsSize; i++) {
        if (nums[i] > nums[i + 1])  {
            hi = i;
            low = i + 1;
            count ++;
            if(2 <= count) {
                ret = false;
                break;
            }
        }
    }

    if(count == 0) {
        return true;
    }

    //printf("hi = %d, low = %d, numsSize = %d\n",hi, low, numsSize);

    if(count == 1) {
        if(low == numsSize - 1) {
            ret = true;

        }
        else {
        
            if(nums[low] == nums[low + 1]) {
            //do_hi();
            if (hi == 0) {
                ret = true;
            }
            else {
                if (nums[hi - 1] == nums[hi]) {
                    ret = false;
                }
                else {
                    if (nums[hi - 1] > nums[low]) {
                        ret = false;
                    }
                    else {
                        ret = true;
                    }
                }
            }
        }
        else if (nums[low] < nums[low + 1]) {
            if (nums[hi] <= nums[low + 1]) {
                //do_low();
                ret = true;
            }
            else {
                    //do_hi();
                    if (hi == 0) {
                        ret = true;
                    }
                    else {
                        if (nums[hi - 1] == nums[hi]) {
                        ret = false;
                    }
                    else {
                        if (nums[hi - 1] > nums[low]) {
                            ret = false;
                        }
                        else {
                            ret = true;
                        }
                    }
            }
                                    
            }
        }
        }
    }

    return ret;
}