int myAtoi(char * str){
    int i = 0;
    int tag = 1;
    double sum = 0;
    while (str[i] == ' '){
        i++;
    }
    /*判断正负*/
    if (str[i] == '+'){
        i++;
    }
    else if (str[i] == '-'){//细节：两个判断只会进入一个
        tag = -1;
        i++;
    }
    /*转换*/
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9'){
            sum = sum*10 + (str[i] - '0');
            i++;
    }

    if (sum != (int)sum){//溢出判断
        return tag == 1? INT_MAX : INT_MIN;
    }
    /*1.为了进行溢出判断，我选了double作为sum的类型，此时是可以成功的。同样占八个字节，我将sum定义成long类型，就会出现数字溢出，这是为啥？
    2.如果还是把sum定义成long类型，把这个判断放while里面，仍然不会报错？如下：
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9'){
            sum = sum*10 + (str[i] - '0');
            i++;
        if (sum != (int)sum){//溢出判断
        return tag == 1? INT_MAX : INT_MIN;
    }
    }
*/

    sum *= tag;
    return sum;
    
}