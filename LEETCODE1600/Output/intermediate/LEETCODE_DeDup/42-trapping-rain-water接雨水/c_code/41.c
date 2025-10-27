int trap(int* height, int heightSize){
    int num=0;      //计算可装雨滴数量
    int i,j,k;      
    int dex=-1;     //
    for(k=0;k<heightSize;k++)
    {
        if(height[k]!=0)
        {
            break;
        }
    }
    for(i=k;i<heightSize;i++)
    {
        for(j=i+1;j<heightSize;j++)
        {
            if(height[i]<=height[j])
            {
                dex=j;
                while(i<j)
                {
                    num+=(height[i]-height[--j]);
                }
                break;
            }
        }
        if(i<dex)
        {
            i=dex-1;
        }
        else 
        {
            height[i]--;
            if(height[i]>0)
            {
                i--;
            }
        }
    }
    return num;
}