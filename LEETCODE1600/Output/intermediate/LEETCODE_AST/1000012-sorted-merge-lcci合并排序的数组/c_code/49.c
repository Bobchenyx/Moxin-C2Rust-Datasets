void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    //printf("%d\n",ASize);
    int ABSize=ASize;
    ASize=ABSize-BSize;
    int ab[ABSize];
    int ia=0,ib=0,iab=0;
    int a,b;
    while(iab<ABSize)
    {
        if(ia<ASize)
        {
            a=A[ia];
        }
        else
        {
            a=INT_MAX;
        }

        if(ib<BSize)
        {
            b=B[ib];
        }
        else
        {
            b=INT_MAX;
        }
        if(a>b)
        {
            ab[iab++]=b;
            ib++;
        }
        else
        {
            ab[iab++]=a;
            ia++;
        }
    }
   // A=NULL;
    for(int i=0;i<ABSize;i++)
    {
        A[i]=ab[i];
   //printf("%d ",ab[i]);
    }
}