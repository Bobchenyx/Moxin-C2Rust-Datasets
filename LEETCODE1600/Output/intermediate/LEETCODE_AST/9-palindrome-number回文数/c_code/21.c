bool isPalindrome(int x){
    if (x<0) return false;
    int div=1;
    while(x/div>=10) div*=10;//找到离x最近的整十整百整千数
    while(x!=0){
        int left=x/div; //取最左面的一位数
        int right=x%10; //取最右面的一位数
        if(left!=right)
        return false;
       else{
           x=(x-left*div-right)/10;
            div=div/100;
            } 
            
    }
    return true;
}