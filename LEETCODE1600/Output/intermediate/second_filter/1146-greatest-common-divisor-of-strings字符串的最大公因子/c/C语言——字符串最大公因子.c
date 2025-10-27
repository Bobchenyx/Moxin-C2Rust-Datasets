char * gcdOfStrings(char * str1, char * str2){
    int gcd(int a,int b);                   //声明
    int str1_len=strlen(str1),str2_len=strlen(str2);
    char *p=(char *)calloc((str1_len+str2_len+1),sizeof(char));
    char *q=(char *)calloc((str1_len+str2_len+1),sizeof(char));
    strcpy(p,str1);strcpy(q,str2);          //复制
    strcat(p,str2);strcat(q,str1);         //拼接
    if(strcmp(p,q)!=0)return "";
    //求字串
    int len = str1_len>str2_len?gcd(str1_len,str2_len):gcd(str2_len,str1_len);
    char *res=(char *)calloc(len+1,sizeof(char));
    strncpy(res,str1,len);
    return res;
}
int gcd(int a,int b){                   //递归求最大公约数
    return b==0?a:gcd(b,a%b);
}