bool isPalindrome(int x){
    if(x < 0) return false;//负数不可能是回文数；
    int len = 0, tmp = x;
    while(tmp){
        len++;
        tmp /= 10;
    }//这里用来计算这个数的长度；
    tmp = x;
    int i = 1;
    len = len-1;//这里jlen-1是为了为pow做准备的；
    while(len > 0){
        if(tmp/(int)pow(10,len) != tmp%(int)pow(10, i)) return false;//如果不相等就返回false；
        这里举个例子，比如121，那么就是121/100 ！= 121%10；
        tmp -= (tmp/(int)pow(10,len))*(int)pow(10, len); //121-100；
        tmp /= 10; //21/10
        len -= 2;;//这里为什么-2呢，因为一个数比如121，每对比一次就是少了两位变成了2；
   }
    return true;
}