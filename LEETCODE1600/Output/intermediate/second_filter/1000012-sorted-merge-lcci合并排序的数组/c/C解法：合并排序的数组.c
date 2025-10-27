void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int *lst=(int*)malloc(sizeof(int)*(m+n));
    int i=0,j=0;
    int pos=0;
    while(i<m&&j<n)
    {
        if(A[i]<=B[j])
        {
            lst[pos++]=A[i++];
        }
        else
        {
            lst[pos++]=B[j++];
        }
    }
    while(i<m)
    {
        lst[pos++]=A[i++];
    }
    while(j<n)
    {
        lst[pos++]=B[j++];
    }
    for(int i=0;i<m+n;i++)
    {
        A[i]=lst[i];
    }
    free(lst);
}