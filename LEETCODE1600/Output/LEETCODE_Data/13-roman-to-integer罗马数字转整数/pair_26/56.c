int getValue(char val){
    switch(val){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;    
    }
    
}
int romanToInt(char * s){
    int cur,fut,sum=0;
    int i;
    for(i=0;i+1<strlen(s);i++){
        cur=getValue(s[i]);
        fut=getValue(s[i+1]);
        if(cur<fut) sum-=cur;
        else sum+=cur;
    }
    sum+=getValue(s[strlen(s)-1]);
    return sum;

}