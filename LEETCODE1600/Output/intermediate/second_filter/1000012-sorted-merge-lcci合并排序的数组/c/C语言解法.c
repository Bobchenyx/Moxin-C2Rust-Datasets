void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int i = 0;
    int j = 0;
    for(i = 0; i < n; i++)
    {
        A[m+i] = B[i];
    }
    for(i = 0;i < m+n-1; i++)
    {
        for(j = 0;j < m+n-1-i;j++)
        {
            int tmp = 0;
            if(A[j] > A[j+1])
            {
                tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
            }
        }
    }

}