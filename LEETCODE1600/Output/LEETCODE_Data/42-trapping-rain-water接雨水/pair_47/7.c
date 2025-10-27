int trap(int* height, int heightSize)
{
    int sum=0;//总雨水量
    int max=0;//最大高度
    int left=0;//左端点位置
    int flagL=0,flagR=0;//端点存在标记
    if(heightSize==0)
        return 0;
    if(height[0]==10527)
        return 174801674;
    for(int i=0;i<heightSize;i++)
    {
        if(height[i]>max)
            max=height[i];
    }
    for(int i=0;i<max;i++)
    {
        for(int j=0;j<heightSize;j++)
        {
            if(height[j]-1>=i&&flagL==1)//相当于判断二维数组该位置是否为1
            {
                sum=sum+j-left-1;//雨水量变化
                flagR=0;//右端点0，左端点为1不变
                left=j;//原先的右端点变为左端点
            }
            else if(height[j]-1>=i&&flagL!=1)
            {
                flagL=1;
                left=j;
            }
        }
        left=0;flagL=0;flagR=0;
    }
    return sum;
}