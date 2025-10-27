#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int maxArea(int* height, int heightSize){
    
#if 0
    int i, j;
    int area, max = 0;
    for (i = 0; i < heightSize; i++) {
        for (j = i + 1; j < heightSize; j++) {
            area = (j - i)*MIN(height[i], height[j]);
            max = MAX(max, area);
        }
    }
#else
    int i = 0, j = heightSize - 1;
    int area, max = 0;

    while (j > i) {
        area = (j - i) * MIN(height[i],height[j]);
        max = MAX(area, max);
        if (height[i] > height[j])      //两边哪个墙低就哪边变动
            j--;
        else
            i++;
    }

#endif
    return max;
}