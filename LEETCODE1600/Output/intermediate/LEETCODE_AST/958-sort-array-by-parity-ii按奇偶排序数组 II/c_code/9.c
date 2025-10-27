/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* A, int ASize, int* returnSize)
{
    if (A == NULL || returnSize == NULL) {
        return NULL;
    }

    int i = 0;          // 偶数下标
    int j = ASize - 1;  // 奇数下标
    while (i < ASize && j > 0) {
        while (i < ASize && A[i] % 2 == 0) { // 找到偶数下标但值为奇数的数
            i += 2;
        }
        if (i >= ASize) {
            break;
        }

        while (j > 0 && A[j] % 2 != 0) { // 找奇数下标但值为偶数的数
            j -= 2;
        }
        if (j <= 0) {
            break;
        }

        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    *returnSize = ASize;
    return A;
}