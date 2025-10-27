bool isPalindrome(int x){
    long w=1,g=10,n=0;
    int i;
    if(x<0)
        return false;
    while(x/w != 0){
        w=w*10;
        n++;
    }
    w = w/10; //找最高位
    for(i=0;i<n/2;i++){
        if(x/w!=x%g) //最高位和最低位比较
            return false;
        else{
            x=(x%w)/g; //去掉最高位和最低位
            w = w/100; //去掉两位，所以w缩小100
        }
    }
    return true;

}