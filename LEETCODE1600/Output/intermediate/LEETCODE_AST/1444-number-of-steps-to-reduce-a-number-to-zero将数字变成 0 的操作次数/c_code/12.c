int numberOfSteps (int num){
int count=0;
while(num){
    if(!(num%2)){
        num=num/2;
    }else{
        num=num-1;
    }
    count++;
}
return count;
}