int min(int a,int b)
{
    return a>b?b:a;
}
int maxArea(int* height, int heightSize){
    int i=0,j=heightSize-1,max=(j-i)*min(height[i],height[j]);//i,j分别指向两端
    while(j>i)
    {
        if(height[i]<height[j])
            i++;
        else
            j--;
        if(max<(j-i)*min(height[i],height[j]))
        max=(j-i)*min(height[i],height[j]);
    }
    return max;
}