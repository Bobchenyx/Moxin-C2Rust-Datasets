int maxArea(int* height, int heightSize){
    int max=0;
    int area=0;
    for(int i=0;i<heightSize-1;i++)
    {
        for(int j=i+1;j<heightSize;j++)
        {
            int min=height[i]<height[j]?height[i]:height[j];
            area=(j-i)*min;
            if(area>max)
                max=area;
        }
    }
    return max;
}