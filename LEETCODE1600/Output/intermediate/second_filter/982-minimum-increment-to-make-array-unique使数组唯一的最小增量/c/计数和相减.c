int maxnum(int* A, int Asize){
    int max=A[0];
    for(int i=1;i<Asize;i++)
    if(max<A[i]) max=A[i];
    return max;
}
int minnum(int* A, int Asize){
    int min=A[0];
    for(int i=1;i<Asize;i++)
    if(min>A[i]) min=A[i];
    return min;
}

int minIncrementForUnique(int* A, int ASize){
   if(ASize==0) return 0;
   int max=maxnum(A,ASize);
   int min=minnum(A,ASize);
   int size=max-size+1;
   int* count =(int*)calloc(size,sizeof(int));
   int plus=0;
   int acount=0;
   int bcount=0;
   for(int i=0;i<ASize;i++)
   count[A[i]-min]++;
   for(int i=0;i<size;i++){
        acount+=count[i]*i;    //在count中对数组求和
        for(int k=0;k<count[i];k++){
            bcount+=plus;      //计算累加的和
            plus++;            //计算累加值
        }
        if(plus<=i+1){
            plus=i+1;           //如果累加值小于下标+1 ，说明之前所有的0已经全部被填满，累加值需要跳跃
        }
   }
   return bcount-acount;
}