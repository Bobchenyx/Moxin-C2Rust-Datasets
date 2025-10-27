int unique_len(char *s){
    int i=0,a[128]={0};
    for(;s[i]!='\0';i++){
        a[s[i]]+=1;
        if(a[s[i]]>1){
            break;
        }
    }
    return i;
}
void get_son(char* s,int i,int len,char* a){
    int j=0;
    for(;i<len;i++){
        a[j]=s[i];
        j++;
    }
}
int lengthOfLongestSubstring(char * s){
    int len=strlen(s),i=0,max=0,temp=0;
    char a[50000]={'\0'};
    for(;i<len;i++){
        get_son(s,i,len,a);
        temp=unique_len(a);
        max=max>temp?max:temp;
        if(len-i+1<=max) break;
    }
    return max;
}