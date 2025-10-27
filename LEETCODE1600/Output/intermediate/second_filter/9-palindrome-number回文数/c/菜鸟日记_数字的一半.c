bool isPalindrome(int x){
/*方法一：数组存放拆分对比*/
  /*  
    if (x < 0){
        return false;
    }
    int array[12]  = {0};
    int i = 0;
    int num = x;
    int size = -1;
    while (num != 0){
        array[i] = num%10;
        num /= 10;
        size++;
        i++;
    }
    i = 0;
    bool tag = true;
    while (size > i){
        if (array[size--] != array[i++]){
            tag = false;
        }
    }
    return tag;
    */
/*方法二：反转一半的数字*/
    if (x < 0 || (x % 10 == 0 && x != 0)){
        return false;
    }
    int num = 0;
    while (x > num){//如果num >= x,此时num已经是x的一倍了，那么处理的位数也已经过半。
        num  = num*10 + x%10;
        x /= 10;
    }
    return x == num || x == num/10;//x有可能除过头，导致num比大一个量级

}