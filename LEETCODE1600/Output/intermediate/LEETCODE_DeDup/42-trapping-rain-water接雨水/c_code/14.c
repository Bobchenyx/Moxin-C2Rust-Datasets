#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//【算法思路】数组。数组为为上升序列，水平序列和下降序列三部分，简化处理逻辑。
int trap(int* height, int heightSize){
    if(heightSize <= 1) {
        return 0;
    }

    //找到序列最大值,将序列分成三部分
    int max = height[0];
    int mid_s = 0;
    int mid_e = 0;

    for(int i = 1; i < heightSize; i++) {
        if(height[i] > max) {
            max = height[i];
            mid_s = i;
            mid_e = i;
        } else if(height[i] == max) {
            mid_e = i;
        }
    }

    //printf("max = %d, mid_s = %d, mid_e = %d\n", max, mid_s, mid_e);

    int sum = 0;

    //处理前段
    int last = height[0];
    for(int i = 1; i <= mid_s; i++) {
        if(height[i] > last) {
            last = height[i];
        } else {
            sum += last - height[i];
        }
    }

    //处理中段
    last = max;
    for(int i = mid_s + 1; i<= mid_e; i++) {
        sum += last - height[i];
    }

    //处理后段
    last = height[heightSize - 1];
    for(int i = heightSize - 2; i >= mid_e; i--) {
        if(height[i] > last) {
            last = height[i];
        } else {
            sum += last - height[i];
        }
    }

    return sum;
}