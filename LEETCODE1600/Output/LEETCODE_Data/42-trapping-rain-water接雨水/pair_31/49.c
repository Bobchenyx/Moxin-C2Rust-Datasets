//反向排空相减法
int trap(int* height, int heightSize){
    if(heightSize == 0)
        return 0;
    int maxHeight = 0;
    for(int i=0;i<heightSize;i++)
        if(height[i] > maxHeight)
            maxHeight = height[i];
    int copy[heightSize];
    for(int i=0;i<heightSize;i++)
        copy[i] = maxHeight;
    //从左向右找一轮，再从右向左找一轮，保留新数组中间水，最后两数组高度相减就是保留水
    //为了加速，可以只循环height中的heightSize个数，这样时间复杂度就从O（heightSize * maxHeight) 变为 O(heightSize * heightSize)
    //很懒，就不再把height新创数组并在排序了
    for(int i=0;i<heightSize;i++)       //改造新数组
    {
        //从两边到中间，一层一层的削
        int left=0,right=heightSize-1;
        while(left < heightSize && height[left] <= height[i] )      //碰到比当前height[i]高的墙就不再削了
        {
            if(copy[left] > height[i])      //超过会被削
            {
                copy[left] = height[i];
            }

            left++;
        }
        while(right >=0 && height[right] <= height[i])
        {
            if(copy[right] > height[i])
                copy[right] = height[i];
            right--;
        }
    }
    //两数组高度相减
    int ans=0;
    for(int i=0;i<heightSize;i++)
    {
        ans += copy[i] - height[i];
    }
    return ans;
}