int balancedStringSplit(char * s){
    int num = 0, index = 0, leap = 0;
    //有多少个RL/LR边界就有最多多少个数量
    while(index < strlen(s)){
        int target = s[index];
        int next_target = s[index+1];
        if(target == next_target){
            index++;
            leap++;
        }else{
            index+=leap+2;
            num++;
            leap = 0;
        }
    }
    return num;
}