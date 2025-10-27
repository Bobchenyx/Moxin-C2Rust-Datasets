//双指针，移动法
int maxArea(int* height, int heightSize){

    if ( heightSize < 2) return 0;

    int left = 0 ;
    int right = heightSize - 1;
    int minHeight = 0;
    int max_area = 0;

    while ( left < right) {
        minHeight = height[left] >  height[right] ? height[right] : height[left];
        if ((right - left ) * minHeight > max_area ) {
            max_area = (right - left ) * minHeight;
        }
        //谁小谁先动
        if (height[left] < height[right]){
            left++;
        } else{
            right--;
        }
        
    }
    return max_area;
}