typedef struct
{
    int index;
    int val;
}Temp;
int largestRectangleArea(int* heights, int heightsSize){
    int* long_right = (int*)malloc(sizeof(int) * heightsSize);
    int* long_left = (int*)malloc(sizeof(int) * heightsSize);
    Temp* stack = (Temp*)malloc(sizeof(Temp) * heightsSize);
    int i;
    int max = 0;
    for(i = 0; i < heightsSize; i++) {
        long_right[i] = 0;
        long_left[i] = 0;
    }
    
    int top = -1;
    for(i = 0; i < heightsSize; i++) {
        while(top > -1 && stack[top].val > heights[i]) {
            long_right[stack[top].index] = i - stack[top].index;
            top--;
        }
        top++;
        stack[top].val = heights[i];
        stack[top].index = i;
    }
    
    for(i = 0; i < top + 1; i++) {
        long_right[stack[i].index] = heightsSize - stack[i].index;
    }

    top = -1;
    for(i = (heightsSize - 1); i >= 0; i--) {
        while(top > -1 && stack[top].val > heights[i]) {
            long_left[stack[top].index] = stack[top].index - i - 1;
            top--;  
        }
        top++;
        stack[top].val = heights[i];
        stack[top].index = i;
    }
    
    for(i = 0; i < top; i++) {
        long_left[stack[i].index] = stack[i].index;
    }

    for(i = 0; i < heightsSize; i++) {
        printf("num[%d] right:%d left:%d\n", i, long_right[i], long_left[i]);
        long_left[i] = long_left[i] + long_right[i];
        max = fmax(max, heights[i] * long_left[i]);
    }
    return max;
}