#include <stdlib.h>
#define MAX_N 500

int compare(const void* a, const void* b)
{
	return *(int*)a > *(int*)b;
}

int numberOfBoomerangs(int** points, int pointsSize, int* pointsColSize)
{
    if (points == NULL || pointsSize < 3 || pointsSize > 500) {
        return 0;
    }

    int distance[MAX_N] = {0};  // 距离数组
    int sum = 0;
    int i;	// 指针，选择锚点
    int j;	// 指针，计算距离

    for (i = 0; i < pointsSize; i++) {
    	// 计算每一点到点i的距离
    	for (j = 0; j < pointsSize; j++) {	
    		distance[j] = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) +
    					  (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
    	}

    	// 对距离按升序排序
    	qsort(distance, pointsSize, sizeof(int), compare);

    	int currCount = 1;  // 当前计数
    	
    	// 遍历排序后的距离，统计个数
    	for (j = 1; j < pointsSize; j++) {
    		if (distance[j] != distance[j - 1]) {
    			sum += currCount * (currCount - 1);
    			currCount = 1;
    		} else {
    			currCount++;
    		}
    	}

    	// 记得统计最后一个单词
    	sum += currCount * (currCount - 1);
    }

    return sum;
}