int searchInsert(int* nums, int numsSize, int target){
    for(int i=0;i<numsSize;i++){
        if(i==numsSize-1&&target>*(nums+i)){
            return numsSize;
        }
        if(target>*(nums+i)&&target<=*(nums+i+1)){
            return i+1; 
        }
        if(target<=*(nums)){
            return 0;
        }  
    }
    return -1;//错误返回
}