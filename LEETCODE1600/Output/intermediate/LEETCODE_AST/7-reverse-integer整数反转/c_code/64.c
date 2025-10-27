double ppow(int n);
int reverse(int x){
    long result=0;
    int i=0;
    int *array;
    array=(int *)malloc(32*sizeof(int));//
    //int array[32];
    while(1&&i<32){
    //while(x!=0){
        // array[i] = x%10;
        // x = x/10;
        // i++;
        array[i]=x%((int)ppow(i+1))/(int)ppow(i);
        if(array[i]==0&&x/(int)ppow(i)==0) break;
        i++;
    }
    for(int k=0;k<i;k++){
        result=result+(long)array[k]*ppow(i-k-1);
    }
    if((int)result != result){
        return 0;
    }
    return (int)result;

}
//计算10的n次方
double ppow(int n){
    double result=1;
    if(n==0) return 1;
    for(int i=0;i<n;i++){
        result=result*10;
    }
    return result;
}