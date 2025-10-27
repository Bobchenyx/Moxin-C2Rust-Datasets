#include <string.h>
int gcd(int a,int b){
    while(b!=0){
        int c=a;
        a=b;
        b=c%a;
    }
    return a;
}
char * gcdOfStrings(char * str1, char * str2){
    char*res=NULL;
    if(*str1!=*str2){
        res=(char*)malloc(sizeof(char));
        res[0]=0;
        return res;
    }
    int len1=strlen(str1),len2=strlen(str2);
    int len3=gcd(len1,len2);
    int i=0,j=0;

    char *s=(char*)malloc((len1+len2)*sizeof(char));//bu xu yao liu yi wei gei \0 
    while(i<len1){
        s[i]=str1[i];
        i++;
    }
    while(j<len2){
        s[i+j]=str2[j];
        j++;
    }
    for(i=0;i<len3;i++){
        int flag=0;
        char t=s[i];
        for(j=i;j<len1+len2;j+=len3){
            if(s[j]!=t){
                flag=1;
                break;
            }
        }
        if(flag==1){
            res=(char*)malloc(sizeof(char));
            res[0]=0;
            return res;
        }
    }
    free(s);
    res=(char*)malloc(sizeof(char)*(len3+1));
    res[len3]=0;
    for(i=0;i<len3;i++){
        res[i]=str1[i];
    }
    return res;
}