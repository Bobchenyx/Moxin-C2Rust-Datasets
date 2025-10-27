int min(int x, int y){
    int t = (x < y)?x:y;
    return t;
}

int maxArea(int* height, int heightSize){
    int a[heightSize-1];
    int i = 0;
    int j = heightSize - 1;
    for(int k = 0; k < heightSize -1; k++){
        if(min(height[i], height[j]) == height[i]){
            a[k] = (j - i) * height[i];
            i++;
        }
        else{
            a[k] = (j - i) * height[j];
            j--;
        }
    }
    int max = a[0];
    for(int k = 1; k < heightSize - 1; k++){
        max = (a[k] > max)?a[k]:max;
    }
    return max;
}