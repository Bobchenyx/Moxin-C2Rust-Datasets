/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool isSelfDiv(int x){
    if(x==0) return false;
    int tmp=x;
    while(x!=0){
        int y=x%10;
        if(y==0||tmp%y!=0) return false;
        x/=10;
    }
    return true;
}

int* selfDividingNumbers(int left, int right, int* returnSize){
    int count=0,i;
    int *num=(int *)malloc(sizeof(int)*200);
    for(i=left;i<=right;i++){
        if(i==0) continue;
        if(isSelfDiv(i)){
            num[count]=i;
            count++;
        }
    }
    *returnSize=count;
    return num;

}