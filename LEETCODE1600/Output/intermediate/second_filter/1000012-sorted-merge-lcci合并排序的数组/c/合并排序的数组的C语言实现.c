int getIndex(int* A, int start, int end)
{
    int tmp = A[start];
    while(start < end)
    {
        while((start<end) && (A[end] >= tmp))
        {
            end--;
        }
        A[start] = A[end];
        while((start<end) && (A[start] <= tmp))
        {
            start++;
        }
        A[end] = A[start];
    }
    A[start] = tmp;
    return start;
}

void quickSort(int* A, int start, int end)
{
    if(start < end)
    {
        int index = getIndex(A, start, end);
        quickSort(A, start, index);
        quickSort(A, index+1, end);
    }
    return;
}

void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    /* 将数组B 复制 到数组A */
    int k = 0;
    for(int i=m; i<m+n; i++)
    {
        A[i] = B[k];
        k++;
    }

    /* 快速排序 */
    quickSort(A, 0, m+n-1);
    return;
}