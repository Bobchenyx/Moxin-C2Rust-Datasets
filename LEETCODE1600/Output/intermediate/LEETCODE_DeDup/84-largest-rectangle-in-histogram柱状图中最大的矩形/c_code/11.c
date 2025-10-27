int largest(int* heights,int low,int high,int min,int *max)
{
    int max0=0,min0=heights[low];
    for(int i=low;i<=high;i++)
    {
        if(i==high||heights[i]<=min)
        {
            return i;
        }
        
        if(heights[i]>min0)
        {
            i=largest(heights,i,high,min0,max);
            i--;
            max0=(i-low+1)*min0;
            if(max0>*max)
                *max=max0;
        }
        else
        {
            min0=heights[i];
            max0=(i-low+1)*min0;
            if(max0>*max)
                *max=max0;
        }
    }
    return 0;
}

int largestRectangleArea(int* heights, int heightsSize){
    int max=0;
    if(heightsSize<=0)
        return max;
    
    largest(heights,0,heightsSize,-1,&max);
    return max;
}