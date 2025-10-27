bool isUgly(int num){
    if (num == 1) return true;
    while (true){
        int last = num;
        num = num % 2 ? num : num >> 1; //整除2
        num = num % 3 ? num : num / 3;  //整除3
        num = num % 5 ? num : num / 5;  //整除5
        if (num == last) return false;  //无法继续整除
        if (num == 1) break;            //最终得到1
    }
    return true;


}