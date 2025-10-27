int maxArea(int* height, int heightSize){
    int left = 0,right=heightSize-1;
    int maxArea = 0;
    int curArea = 0;
    while(left < right){
        curArea = (right-left)*(height[left]>height[right]?height[right]:height[left]);
        if(curArea > maxArea) maxArea = curArea;
        if(height[left]>height[right]) right--;
        else left++;
    }
    return maxArea;
}