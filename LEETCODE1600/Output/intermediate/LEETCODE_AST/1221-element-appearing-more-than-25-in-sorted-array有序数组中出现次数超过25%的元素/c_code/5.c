int findSpecialInteger(int* arr, int arrSize) {
    for (int *p = arr, *q = arr + arrSize / 4; ; p++, q++)
        if (*p == *q) return *p;
    return 0;  
}
// 执行用时 :8 ms, 在所有 c 提交中击败了100.00%的用户