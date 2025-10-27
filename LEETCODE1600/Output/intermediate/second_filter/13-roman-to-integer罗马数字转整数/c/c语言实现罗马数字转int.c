![}_YKE10HG2ST2SIA5JS\]LCL.png](https://pic.leetcode-cn.com/9adf93f51c2b334a6d961f7352b9081b012106d64c06748d748c839abd4bdcc0-%7D_YKE10HG2ST2SIA5JS%5DLCL.png)

/**********************************************************************
** 利用switch来判断的话，比if语句运行时间短                             **
** 用数组存放的话，太占内存了，因此使用该方法                            **
**********************************************************************/
int charToInt( char ch){
    switch( ch ){
        case 'I':{
            return 1;
        }
        case 'V':{
            return 5;
        }
        case 'X':{
            return 10;
        }  
        case 'L':{
            return 50;
        }
        case 'C':{
            return 100;
        }
        case 'D':{
            return 500;
        }
        case 'M':{
            return 1000;
        }
        //养成好习惯就是这个一定要和case成对出现，即使不写内容
        default:{  
        }
    }
    return 0;
}

/**********************************************************************
** 注意观察你会发现，需要做减法的情况是右边的 int                        **
** 大于左边的时候，因此可以比较不严谨的认定只要右边                       **
**  大于左边，直接减去该值，同时指针再右移一位，节省时间                  **
**********************************************************************/
int romanToInt(char * s){
    int sum = 0;
    while ( *s != '\0'){
        // 比较右边的int值是否大于左边
        if ( charToInt ( *( s + 1 ) ) > charToInt ( *s ) ){
            //大于的话，就减去左边的值，加上右边的值，
            sum += ( charToInt ( *( s + 1 ) ) - charToInt ( * s ) ) ;
            // 直接在这进行指针移位可以节省时间
            s++;
        } else{
            //正常情况下视为加法即可
            sum += charToInt ( * s );
        }
        //指针右移
        s++;
    }
    return sum;
}