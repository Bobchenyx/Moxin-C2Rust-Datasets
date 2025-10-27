bool isPalindrome(int x){
    if(x<0)return false;
    int num = 1,temp=x;
    while(temp/=10)num++;
    while(1){
        if(num<2)return true;
        int temp = (int)pow(10,num-1);
        if(x/temp==x%10){
            x%=temp;
            x/=10;
            num-=2;
        }else return false;
    }
    return false;
}