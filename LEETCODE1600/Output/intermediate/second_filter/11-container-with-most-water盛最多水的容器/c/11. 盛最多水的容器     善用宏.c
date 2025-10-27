#define MAX(a,b) ((a)>(b)?(a):(b))

int maxArea(int* height, int heightSize){
    int left = 0, right = heightSize - 1;
    int maxA = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            maxA = MAX(maxA, height[left]*(right - left));
            left++;
        } 
        else {
            maxA = MAX(maxA, height[right]*(right - left));
            right--;
        }  
    }
    return maxA;
}