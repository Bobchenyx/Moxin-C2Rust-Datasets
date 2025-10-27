void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int i=m-1;
    int j=n-1;
    int max=m+n-1;
   while(j>=0&&i>=0)
    {
        if(A[i]>=B[j])
        {
            A[max--]=A[i--];
        }
        else
        {
            A[max--]=B[j--];
        }
    }
    while(i>=0)
    {
        A[max--]=A[i--];
    }
    while(j>=0)
    {
        A[max--]=B[j--];
    }



}