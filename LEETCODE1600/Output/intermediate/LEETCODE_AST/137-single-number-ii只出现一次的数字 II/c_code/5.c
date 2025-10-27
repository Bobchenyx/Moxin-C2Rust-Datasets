int singleNumber(int* nums, int numsSize){
    int s[32] = {0}; // 32 = sizeof(int)
    int i, j;
        
    for(i = 0; i < numsSize; i++) {     
        for (j = 0; j < 32; j++) {
            s[j] += (((unsigned int)nums[i])>>j) % 2;
            if(s[j] == 3) 
                s[j] = 0;
        }
    }

    int res = s[0];
    unsigned int tag = 1;
       
    for(j = 0; j < 32; j++) {
        if(s[j])
            res |= tag<<j;
    }

    return res;
}