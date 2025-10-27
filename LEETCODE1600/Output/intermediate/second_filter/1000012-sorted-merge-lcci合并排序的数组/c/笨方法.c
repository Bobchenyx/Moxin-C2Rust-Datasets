void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int flag=1;
    int m1=m;
    int index=0;
    for(int i=0;i<n;i++)
    {
        for(int j=index;j<m1;j++)
        {
            if(B[i]<A[j])
            {
                flag=0;
                for(int k=m1++;k>j;k--)
                    A[k]=A[k-1];
                A[j]=B[i];
                index=j+1;
                break; 
            }
            flag=1;
        }
        if(flag)
        {
            A[m1++]=B[i];
        }
            
    }
}