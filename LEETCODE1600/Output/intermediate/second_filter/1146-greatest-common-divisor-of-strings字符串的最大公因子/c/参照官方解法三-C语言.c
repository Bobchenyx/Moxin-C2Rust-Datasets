int gcd(int a,int b){//求两个数的最大公因数，辗转相除法，递归
    int min = (a<b?a:b), max = (a>b?a:b);
    if(max % min == 0) return min;
    return gcd(min,max % min);
}
char * gcdOfStrings(char * str1, char * str2){
    //在拼接字符串之前要先申请足够容纳两个字符串所有字符的字符串数组
    char *str1_c = (char *)malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 2));
    char *str2_c = (char *)malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 2));
    strcpy(str1_c,str1);
    strcpy(str2_c,str2);
    strcat(str1_c,str2);//str2直接拼接到str1_c后面，如果没有足够空间会越界
    strcat(str2_c,str1);
    int gcdlen = 0;
    if(strcmp(str1_c,str2_c) == 0){//如果两个字符串相等，strcmp返回0
        gcdlen = gcd(strlen(str1),strlen(str2));
        str1_c[gcdlen] = '\0';
        return str1_c;
    }
    else{
        return "";
    }
}