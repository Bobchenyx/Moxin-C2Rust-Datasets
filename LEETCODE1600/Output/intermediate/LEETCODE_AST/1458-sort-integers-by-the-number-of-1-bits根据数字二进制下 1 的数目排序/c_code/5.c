/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int countBits(int n) {
    int count = 0;
    if(n == 0) return 1;
    while (n) {
        if (n % 2) count++;
        n /= 2;
    }
    return count;
}

bool cmp(int a, int b) {
    int ba = countBits(a);
    int bb = countBits(b);
    if (ba == bb) return a < b;
    else return ba < bb;
}

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int* sortByBits(int* arr, int arrSize, int* returnSize){
    *returnSize = arrSize;
    for (int i = 0; i < arrSize - 1; ++i) {
        for (int j = i + 1; j < arrSize; ++j) {
            if (!cmp(arr[i], arr[j])) {
                swap(arr, i, j);
            }
        }
    }
    return arr;
}