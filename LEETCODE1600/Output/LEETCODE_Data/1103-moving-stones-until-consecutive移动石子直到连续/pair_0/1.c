#include <stdlib.h>
#include <string.h>

// 按照升序排列
int compare(const void* a, const void* b) 
{
    return *(int*)a > *(int*)b;  // 用比较取代减法，防止溢出
}

int* numMovesStones(int a, int b, int c, int* returnSize)
{
    int* answer = (int*)malloc(2 * sizeof(int));
    memset(answer, 0, 2 * sizeof(int));

    int nums[3] = {a, b, c}; // 把三个坐标放进数组nums
    qsort(nums, 3, sizeof(int), compare);//最小坐标为nums[0]，中间坐标为nums[1], 最大坐标为nums[2]
    int delta1 = nums[1] - nums[0] - 1;  // delta1>=0
    int delta2 = nums[2] - nums[1] - 1;  // delta2>=0

    if (delta1 == 0 && delta2 == 0) {
        answer[0] = 0;
    } else if (delta1 == 0 || delta2 == 0) {
        answer[0] = 1;
    } else if (delta1 == 1 || delta2 == 1) {
        answer[0] = 1;
    } else {
        answer[0] = 2;
    }

    answer[1] = delta1 + delta2;

    *returnSize = 2;

    return answer;
}