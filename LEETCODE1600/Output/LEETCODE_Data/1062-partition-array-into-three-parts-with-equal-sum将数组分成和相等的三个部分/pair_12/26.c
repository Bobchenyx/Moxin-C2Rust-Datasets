bool canThreePartsEqualSum(int* A, int ASize){
    if(ASize<3){
        return false;
    }
    int sum=0;
    for(int i=0;i<ASize;i++){
        sum+=A[i];
    }
    float ave= (float)sum/3;
    if((int)ave!=sum/3){
        return false;
    }
    int sum1=0;int flag1;
    int j=0;
    for(;j<ASize;j++){
        sum1+=A[j];
        if(sum1==(int)ave){
            flag1=j;
            break;
        }
    }
    if(j==ASize-1||j==ASize){
        return false;
    }
    int sum2=0;int flag2;
    int m=flag1+1;
    for(;m<ASize;m++){
        sum2+=A[m];
        if(sum2==(int)ave){
            flag2=m;
            m++;
            break;
        }
    }
    if(m>=ASize){
        return false;
    }
    return true;
}