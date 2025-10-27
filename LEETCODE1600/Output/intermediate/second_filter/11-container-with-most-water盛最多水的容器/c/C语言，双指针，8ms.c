int min(int a,int b){
    return (a<b)?a:b;
}

int max(int a,int b){
    return (a>b)?a:b;
}

int maxArea(int* height, int heightSize){
    int left = 0;
    int right = heightSize-1;
    int maxValue = 0;

    while(left!=right){                
        maxValue = max(maxValue,(min(height[left],height[right]) * (right-left)));
        if (height[left]<height[right]){
            left++;            
        }
        else{
            right--;
        }
    }
    return maxValue;        
}