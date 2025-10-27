int singleNumber(int* nums, int numsSize){
    int result = 0;
    for(int i=0;i<32;i++){
        long count =0;        //不用long，力扣的编译器不通过，不让int类型左移31位...
        for(int j=0;j<numsSize;j++){
            count += (nums[j]>>i)&1;
        }
        result += (count%3)<<i;
    }
    return result;
}