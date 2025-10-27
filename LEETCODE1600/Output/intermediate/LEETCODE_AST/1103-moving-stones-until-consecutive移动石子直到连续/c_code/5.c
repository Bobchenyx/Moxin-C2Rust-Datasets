int* numMovesStones(int a, int b, int c, int* returnSize){
    *returnSize = 2;
    int min, mid, max;
    int *answer = malloc(sizeof(int) * *returnSize);
    memset(answer, 0, sizeof(int) * *returnSize);
    
    //排序得出min，mid，max
    if (a > b && a > c) {
        max = a;
        if (b > c) {
            mid = b;
            min = c;
        } else {
            mid = c;
            min = b;
        }
    } else if (b > a && b > c) {
        max = b;
        if (a > c) {
            mid = a;
            min = c;
        } else {
            mid = c;
            min = a;
        }
    } else if (c > a && c > b) {
        max = c;
        if (a > b) {
            mid = a;
            min = b;
        } else {
            mid = b;
            min = a;
        }        
    }

    //情况1，不能移动直接返回
    if (min + 1 == mid && mid + 1 == max) {
        return answer;
    }

    //情况2和3，判断并计算
    answer[1] = max - min - 2;
    if (min == mid - 1 || mid == max - 1 || min == mid - 2 || mid == max - 2) {
        answer[0] = 1;
    } else {
        answer[0] = 2;
    }
    
    return answer;
}