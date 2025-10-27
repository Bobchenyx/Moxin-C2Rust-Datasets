int consecutiveNumbersSum(int N){
    int cnt=0;
    for(int i=0;i*(i+1)<2*N;i++){
        if((2*N)%(i+1)==0&&((2*N)/(i+1)-i)%2==0) cnt++;
    }
    return cnt;
}