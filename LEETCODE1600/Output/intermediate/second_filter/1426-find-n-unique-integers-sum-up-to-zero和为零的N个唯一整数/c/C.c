/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize){
    int* data_buf=(int*)malloc(sizeof(int)*(n));
    memset(data_buf,0,sizeof(int)*(n));
    *returnSize=n;

    for(int i=0,j=n-1;i<n/2;i++,j--){
        data_buf[i]=i+1;
        data_buf[j]=-(i+1);
    }

    return data_buf;
}