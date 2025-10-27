int isJ(char *J,char* s){
    while(*J)if(*J++==s)return 1;
    return 0;
}
int numJewelsInStones(char * J, char * S){
    int count=0;
    while(*S)if(isJ(J,*S++))count++;
    return count;
}