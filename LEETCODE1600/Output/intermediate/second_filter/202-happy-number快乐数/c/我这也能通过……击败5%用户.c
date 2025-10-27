bool isHappy(int n){
    int s=n,sum=0;;
    int temp;
    int count = 0;

    while(n!=1){     
        while(s!=0){
            temp=s % 10;
            sum += temp*temp;
            s /= 10;
        }
        s=n=sum;
        sum=0;
        count++;
        if(count>10000)return false;
    }
    return true;
}