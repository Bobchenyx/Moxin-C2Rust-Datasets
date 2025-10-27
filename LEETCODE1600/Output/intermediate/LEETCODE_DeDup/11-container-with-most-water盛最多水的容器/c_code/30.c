#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))


int maxArea(int* height, int heightSize) {
    int ans = 0, max = 0, area = 0;
    
    for (int i = 0; i < heightSize; i++) {
        for (int j =  i + 1; j < heightSize; j++) {
            area = (j - i) * (MIN(height[i], height[j]));
            max = MAX(max, area);
        }
    }

    return max;
}