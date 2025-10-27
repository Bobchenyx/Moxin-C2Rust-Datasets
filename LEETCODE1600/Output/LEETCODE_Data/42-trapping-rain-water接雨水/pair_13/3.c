int trap(int* height, int heightSize){
    int total = 0;
    short maxIdx = 0;
    short tmph = 0;
    
    for (int i = 0; i < heightSize; i++) {
        total += height[i];
        if (height[maxIdx] < height[i]) {
            maxIdx = i;
        }
    }
    
    total = 0 - total;
    for (int i = 0; i < maxIdx; i++) {
        tmph = tmph < height[i] ? height[i] : tmph;
        total += tmph;
    }
    
    tmph = 0;
    for (int i = heightSize - 1; i >= maxIdx; i--) {
        tmph = tmph < height[i] ? height[i] : tmph;
        total += tmph;
    }
    
    return total;
}