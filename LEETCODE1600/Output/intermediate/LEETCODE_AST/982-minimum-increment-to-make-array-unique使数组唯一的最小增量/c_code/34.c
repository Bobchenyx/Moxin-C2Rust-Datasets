int cmp( const void *a, const void *b ) {
    return *( int *)a - *( int *)b;
}

int minIncrementForUnique(int* A, int ASize){
    int ans = 0;
    qsort( A, ASize, sizeof(A[0]), cmp );
    for( int i = 1; i < ASize; i++ ) {
        if( A[i] <= A[i-1] ) {
            //计算增加的次数
            ans += A[i-1]-A[i]+1;
            //重新赋值让这个数比前一个数大于1
            A[i] = A[i-1]+1;
        }
    }
    return ans;
}