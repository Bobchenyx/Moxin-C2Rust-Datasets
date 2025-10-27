void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    //方法1：直接将B数组插入到A中，然后重新进行排序
    for (int i = 0; i < n; ++i){
        A[m+i] = B[i];
    }
    //重排序，采用最简单的冒泡排序，第一层循环是有多少个数需要比较，第二层循环是每个数需要比较的次数。
    for(int i = 0; i < ASize -1; ++i) {
        for (int j = 0; j < ASize - 1 - i; ++j) {
            if (A[j] > A[j + 1]) {
                int temp = A[j + 1];
                A[j + 1] = A[j];
                A[j] = temp; 
            }
        }
    }

    for(int q = 0; q < ASize; ++q) {
        printf("%d", A[q]);
    }
    printf("\n");
}