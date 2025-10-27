int numberOfSteps (int num){
    return num>1?1+(num%2)+numberOfSteps(num>>1):num;
}