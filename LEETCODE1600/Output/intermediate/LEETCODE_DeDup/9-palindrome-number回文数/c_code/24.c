bool isPalindrome(int x){
    if(x<0){
        return false;
    }
    int k=x;
    long long sum=0,i=0;
    do{
        sum=sum*10+k%10;
        k/=10;
    }while(k!=0);
    if(sum==x){
        return true;
    }
    return false;
}