bool isPalindrome(int x){
    if(x < 0||(x % 10 == 0 && x!=0) ) return false;
    int resultNumber=0;
    while(resultNumber < x){
        resultNumber = resultNumber * 10 + x % 10;//这里是x%10 取当前x的最后一位
        x = x / 10;//没更新一次resultNumber，就相应地要改变一次x
    }
    if(resultNumber == x || x == resultNumber/10)
        return true;
    else
        return false;
    
}