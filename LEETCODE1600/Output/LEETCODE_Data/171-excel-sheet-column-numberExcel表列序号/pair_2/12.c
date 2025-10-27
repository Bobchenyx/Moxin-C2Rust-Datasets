#include <math.h>
int titleToNumber(char * s){
    int i,len,pwo;
    int ans=0;
    len=strlen(s);
    for(i=0;i<len;i++){
        pwo=pow(26,len-i-1);
        // printf("%d",s[i]*pwo);
        ans=(s[i]-64)*pwo+ans;
    }
    return ans;
}