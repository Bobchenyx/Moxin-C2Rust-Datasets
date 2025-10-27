int lengthOfLastWord(char * s){
    if( strlen(s) == 0 ) return 0;
    int i, num=0,prenum=0;
    for( i=0;s[i] != '\0';i++ ){
        if( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') ){
            num +=1;
        }
        if( s[i] == ' ' && num != 0 ){
            prenum = num;
            num = 0;
        }
     }
    if( prenum == 0 || num !=0 ){
        return num;
    }else{
        return prenum;
    }
}