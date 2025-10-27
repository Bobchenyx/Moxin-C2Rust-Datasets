int singleNumber(int* nums, int numsSize){
    int result = 0;
    for(int i = 0; i < 32; i++){//遍历32位
        int temp = 0;//记录所有数字第i位的和
        for(int j = 0; j < numsSize; j++){
            temp += (nums[j] >> i) & 1;//求第i位之和
        }
        if(temp % 3){
            result += 1 << i;//置1
        }
    }
    return result;
}