#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int largestRectangleArea(int* heights, int heightsSize){
    int i,j;
    int area, max = 0, min;

    //if (heightsSize == 1)
      //  return heights[0];

    for (i = 0;i < heightsSize; i++) {
        min = heights[i];
        for (j = i; j < heightsSize; j++) {
            min = MIN(min, heights[j]);
            area = min * (j - i + 1);
            max = MAX(max, area);
        }
    }
    return max;
}