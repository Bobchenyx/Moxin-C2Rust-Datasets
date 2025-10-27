int numJewelsInStones(char * J, char * S){
    int count=0,i=0,j=0,len=0;
    while(S[len]!=0) len++;
    while(J[i]!=0){
        for(j=0;j<len;j++)
            if(S[j]==J[i]) count++;
        i++;
    }
    return count;
}