int numJewelsInStones(char * J, char * S){
    int i,num=0;
    for(i=0;S[i]!='\0';i++){
        if(strchr(J,S[i])) //若S[i]在J中则返回一个S[i]所在位置的指针
            num++;
    }
    
    return num;
}