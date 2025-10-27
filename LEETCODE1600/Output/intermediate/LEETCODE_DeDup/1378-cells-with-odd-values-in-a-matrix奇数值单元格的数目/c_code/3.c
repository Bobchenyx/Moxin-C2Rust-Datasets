int oddCells(int n, int m, int** indices, int indicesSize, int* indicesColSize){
    int nn[50]={0};
    int mm[50]={0};
    int nlen=0,mlen=0,i;
    int *p=&indices[0][0];
    int *p1=nn;
    int *p2=mm;
    for(i=0;i<indicesSize;i++)
    {
        nn[indices[i][1]] ^= 1u;
        mm[indices[i][0]] ^= 1u;
    }
    i=50;
    while(i--)
    {
        nlen+=*p1++;
        mlen+=*p2++;
    }
    return (nlen*n+mlen*m-2*nlen*mlen);
}