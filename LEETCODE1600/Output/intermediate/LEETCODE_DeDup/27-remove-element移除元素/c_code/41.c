/*date:2020.3.4 11：21*/
int removeElement(int* nums, int numsSize, int val){

    if (numsSize == 0){
        return 0;
    }

    int head = 0;
    int rear = numsSize -1;
    while (head != rear){
        if (nums[head] == val){//如果相等
            nums[head] = nums[rear--];
        }
        else{
            head++;
        }
    }
    if (nums[head] != val){
        return head+1;
    }
    else{
        return head;
    }

}