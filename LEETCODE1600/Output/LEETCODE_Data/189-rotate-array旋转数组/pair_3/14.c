void rotate(int* nums, int numsSize, int k){
    //numsSize=numsSize-1;
    int temp,count=0;
    int  current;
    int pre;
    k=k%numsSize;
    for(int start=0;count<numsSize;start++)
    {
        current=start;
        pre=nums[current];
       int next;
        do
        {
            next=(current+k)%numsSize;
            temp=nums[next];
            nums[next]=pre;
            pre=temp;
            current=next;
            count++;
        }
        while(current!=start);
    }

}