void merge(int* A, int ASize, int m, int* B, int BSize, int n)
{
    int i,j,k,l=0;
    for(i=0;i<n;i++)
    {
        if(m==0)
        {
            for(j=0;j<n;j++)
            {
                A[j]=B[j];
            }
        }
        else if(B[i]<A[0])
        {
            for(j=m;j>0;j--)
            {
                A[j]=A[j-1];
            }
            A[0]=B[i];
        }
        else if(B[i]>A[m-1])
        {
            A[m]=B[i];
        }
        else
        {
        for(j=m-1;j>=0;j--)
        {
            if(A[j]<B[i])
            {
                break;
            }
        }
        for(k=m-1;k>j;k--)
        {
            A[k+1]=A[k];
        }
        A[j+1]=B[i];
        }
        m++;
    }
}