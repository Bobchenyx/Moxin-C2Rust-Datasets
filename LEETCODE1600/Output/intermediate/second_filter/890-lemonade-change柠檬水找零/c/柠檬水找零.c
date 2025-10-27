bool lemonadeChange(int* bills, int billsSize){
    int res_5 = 0;
    int res_10 = 0;
    bool is_change = true;
    for(int i = 0; i < billsSize; i++){
        if(bills[i] == 5){
            res_5++;
        }else if(bills[i] == 10){
            res_10++;
            res_5--;
        }else if(bills[i] == 20){
            if(res_10 > 0){
                res_10--;
                res_5--;    
            }else{
                res_5-=3;
            }
            
        }
        if((res_5<0)||(res_10<0)){
            is_change = false;
            break;
        }
    }
    return is_change;
}