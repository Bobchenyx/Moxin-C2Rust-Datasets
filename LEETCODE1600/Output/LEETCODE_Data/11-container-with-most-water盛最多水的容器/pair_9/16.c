int maxArea(int* height, int heightSize){
    if(heightSize<2){
        return 0;
    }
    int len=heightSize-1,low=0,high=heightSize-1,max=0;
    while(low<high){
        if(height[low]<=height[high]){
            if(height[low]*len>max){
                max = height[low]*len;
            }
            low++;
        }else{
            if(height[high]*len>max){
                max = height[high]*len;
            }
            high--;
        }
        len--;
    }
    return max;
}