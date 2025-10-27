/*date：2020.3.4 10：39*/
int removeDuplicates(int* nums, int numsSize){
    if (numsSize == 1){//如果只有一个则直接返回，否则下面会越界
        return 1;
    }
    if (numsSize == 0){
        return 0;
    }
    int head = 0;
    int rear = 1;
    while (rear < numsSize){
        if (nums[head] == nums[rear]){//rear向后扫描，如果和head一样则head不动，rear向后扫描。
        //如果不一样，则前进一格赋值
            rear++;
        }
        else{
            nums[++head] = nums[rear++];
        }
    }
    return head+1;

}