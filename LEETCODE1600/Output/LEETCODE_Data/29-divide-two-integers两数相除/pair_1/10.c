int divide(int dividend, int divisor){
    int changeResult = 0;
    unsigned int undividend, undivisor;
    if(dividend < 0){
        undividend = (unsigned int)0 - dividend;
        changeResult = 1;
    }else{
        undividend = dividend;
    }
    
    if(divisor < 0){
        undivisor = (unsigned int)0 - divisor;
        
        if(changeResult == 1){
            changeResult = 0;
        }else{
            changeResult = 1;
        }
    }else{
        undivisor = divisor;
    }
    
    unsigned int i = undivisor, result = 0,temp = 1;

    while(1){
        if(i > undividend){
            i = i >> 1;
            temp = temp >> 1;
            if(i < undivisor){
                i = undivisor;
                temp = 1;
            }
        }else if( i < undividend){
            i = i << 1;
            temp = temp << 1;
            
        }
        
        if(undividend >= i){
            undividend = undividend - i;
            result = result + temp;

        }else{
            if(temp <= 1){
                if(changeResult == 1){
                    return 0 - result;
                }
                if(result >= 2147483648){
                    return 2147483647;
                }
                return result;
            }
        }
        
    }
}