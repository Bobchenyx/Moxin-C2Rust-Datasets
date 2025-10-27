c [-方法一：二路归并算法]
//二路归并算法
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int indexA=-1,indexB=-1,indexT=-1;
    if(m==0)
    {
        while(indexB<n-1)
        A[indexB]=B[++indexB];
        return;
    }
    int temp[m];
    indexA=-1,indexB=-1,indexT=-1;
    int numA,numB;

    while(indexT<m-1)
        temp[indexT]=A[++indexT];
    printf("%d",temp[indexT]);    
    indexT=-1;
    while(indexT<m-1||indexB<n-1)
    {
        numA=(indexT<m-1)?temp[indexT+1]:3222222;
        numB=(indexB<n-1)?B[indexB+1]:3222222;
        if(numA<numB)
            A[++indexA]=temp[++indexT];
        else
            A[++indexA]=B[++indexB];
    }
}