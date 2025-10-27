int trap(int* height, int heightSize){
    if(heightSize==0)
    {
        return 0;
    }
    int highest=0;
    int highest_id=0;
    for(int i=0;i<heightSize;i++) //找出最高点
    {
        if(highest<height[i])
        {
            highest=height[i];
            highest_id=i;
        }
    }

    int pre_id,cur_id;
    int ans=0;

    //从左向最高点遍历
    pre_id=0;
    while(pre_id<highest_id)
    {
        int stone=0;
        cur_id=pre_id+1;
        while(cur_id<heightSize && height[cur_id]<=height[pre_id] && cur_id<highest_id)
        {
            stone+=height[cur_id];
            cur_id++;
        }
        int len=cur_id-pre_id-1;
        int water=len*height[pre_id]-stone;
        ans+=water;

        pre_id=cur_id;
    }

    //从右向最高点遍历
    pre_id=heightSize-1;
    while(pre_id>highest_id)
    {
        int stone=0;
        cur_id=pre_id-1;
        while(cur_id>=0 && height[cur_id]<=height[pre_id] && cur_id>highest_id)
        {
            stone+=height[cur_id];
            cur_id--;
        }
        int len=pre_id-cur_id-1;
        int water=len*height[pre_id]-stone;
        ans+=water;

        pre_id=cur_id;
    }   

    return ans;
}