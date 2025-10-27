int trap(int* height, int heightSize){
    int all_water = 0,left_water = 0,right_water = 0;
    int temp = 0;
    //int tempmax = 0;
    int maxnum = 0;
    int num;
    if(heightSize <= 1) return 0;
    int i=0,j=0;
    for(i=0;i<heightSize;i++)
    {
        if(height[i]>tempmax)
        {
            //tempmax = height[i];
            maxnum = i;
        }
    }
    i=0;
    while(i<maxnum)
    {
        while(height[i]==0)i++;
        for(j=i+1;j<=maxnum;j++)
        {
            if(height[j]<height[i])
            {
                temp+=height[i]-height[j];
            }
            else
            {
                i=j;
                break;
            }
        }
        left_water+=temp;
        temp=0;
    }
    i=heightSize-1;
    while(i>maxnum)
    {
        while(height[i]==0) i--;
        for(j=i-1;j>=maxnum;j--)
        {
            if(height[j]<height[i])
            {
                temp+=height[i]-height[j];
            }
            else if(height[j]>=height[i])
            {
                i=j;
                break;
            }
        }
        right_water+=temp;
        temp=0;
    }
    all_water = left_water+right_water;
    return all_water;
}