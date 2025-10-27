int maxArea(int* height, int heightSize){
    int low=0,high=heightSize-1;
    int max=high*(height[low]<height[high]?height[low]:height[high]);
    while(low<high)
    {
        int num;
        if(height[low]<=height[high])//短的右移
        {
            low++;
            num=(high-low)*(height[low]<height[high]?height[low]:height[high]);
            if(num>max)
            max=num;
        }
        else if(height[low]>height[high])//长的左移
        {
            high--;
            num=(high-low)*(height[low]<height[high]?height[low]:height[high]);
            if(num>max)
            max=num;
        }
    }
    return max;
}