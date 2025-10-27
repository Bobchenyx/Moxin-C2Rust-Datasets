//计算某个区间的total值。需要找到区间最小值。然后相减。
int calculateValueBetween(int *array, int start, int end) {
    if (end-start< 1) {
        return 0;
    }
    int baseValue = array[start] > array[end] ? array[end]: array[start];
    int value = 0;
    for (int i = start+1; i< end; i++) {
        value += (baseValue - array[i]);
    }
    return value;
}

int trap(int* height, int heightSize){
    if (heightSize < 3) {
        return 0;
    }
    int start=0,next =start+1;
    int totalRain = 0;
    while (start < heightSize && next< heightSize) {
        if (height[start] == 0) {
            start++;
            next = start+1;
        }
        else if (height[next] >= height[start]) {
            start++;
            next = start+1;
        }
        else {
            
            //尝试找到大于start索引值的右侧边值
            while (next < heightSize) {
                if (height[next]>= height[start]) {
                    break;
                }
                next++;
            }
            
            //找到进行计算
            if (next < heightSize) {
                totalRain += calculateValueBetween(height, start, next);
                start = next;
                next = start+1;
                continue;
            }
            
            //尝试找到start右边最大的值
            {
                next = start+1;
                int maxValue = height[next];
                int maxValueIndex = next;
                while (next< heightSize) {
                    if (height[next] > maxValue) {
                        maxValue = height[next];
                        maxValueIndex = next;
                    }
                    next++;
                }
                
                if ((maxValueIndex > start+1) && maxValueIndex < heightSize && maxValue > height[start+1]) {
                    totalRain+= calculateValueBetween(height, start, maxValueIndex);
                    start = maxValueIndex;
                    next = start+1;
                }
                else {
                    start = start+1;
                    next = start+1;
                }
            }
        }
    }
    return totalRain;
}