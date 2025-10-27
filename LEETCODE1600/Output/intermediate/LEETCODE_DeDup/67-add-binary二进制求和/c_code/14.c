char * addBinary(char * a, char * b){
    char *ta=a,*tb=b;
    int c = false;//进位
    int aLen=strlen(a),bLen=strlen(b),max;
    max = aLen>bLen?aLen:bLen;
    char*p = NULL;
    while(*++a!='\0');
    while(*++b!='\0');
    p = aLen>bLen?a:b;
    while(a-ta>0||b-tb>0){
        int tempA = --a>=ta?*a:'0';
        int tempB = --b>=tb?*b:'0';
        *p--;
        *p = tempA+tempB-'0'+c;
        if(*p-'2'>=0){
            *p-=2;
            c=true;
        }else c=false;
    }
    if(c==true){
        char*str = (char*)malloc(sizeof(char)*(max+2));
        str[0] = '1';
        for(int i=1;i<max+1;i++){
            str[i]=p[i-1];
        }
        str[max+1]='\0';
        return str;
    }
    return p;
}