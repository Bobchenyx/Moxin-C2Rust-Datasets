int maxArea(int* height, int heightSize){
    int s = 0, temp;
    for(int i=0;i<=heightSize-2;i++){
        for(int j=i+1;j<=heightSize-1;j++){
            temp = (j - i) * ((height[i] < height[j]) ? height[i] : height[j]);
            s = (temp > s) ? temp : s;
        }
    }
    return s;
}