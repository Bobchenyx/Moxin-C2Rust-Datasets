int maxArea(int* height, int heightSize){
    int i = 0;
    int j = 0;
    int S = 0;
    int max = 0;
    int maxi = 0;
    int maxj = 0;
    for(i = 0; i < heightSize; i++) {
        for(j = i; j < heightSize; j++) {
            S = (height[i] > height[j] ? height[j] : height[i]) * (j - i);
            max = max > S ? max : S;
        }
    }
    //printf("max = %d, maxi = %d, maxj = %d\n",max, maxi, maxj);
    return max;

}