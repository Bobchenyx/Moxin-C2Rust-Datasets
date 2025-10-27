void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int i=0,j=0,k=m;
    while(j<n){
        if(A[i]<=B[j]&&i<k)
            i++;
        else if(A[i]>B[j]&&i<k){
            for(int s=k-1;s>=i;s--)
                A[s+1]=A[s];
            k++;//注意此处用以标明A的初始化数量界限的指针要加1；
            A[i++]=B[j++];
        }
        else{
            A[i++]=B[j++];
        }
    }
}