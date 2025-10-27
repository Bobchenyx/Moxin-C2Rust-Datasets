void reverse(char *r,int len)
{
    for(int i=0,j=len-1;i<j;++i,--j){
        char tmp=r[i];
        r[i]=r[j];
        r[j]=tmp;
    }
}

char * convertToTitle(int n)
{
    char *r=malloc(sizeof(char)*27);
    char *a=malloc(sizeof(char)*27);
    int index=0;
    for(int i=0;i<26;++i)
        a[i]='A'+i;
    while(n>0){
        r[index++]=a[(n-1)%26];
        n=(n-1)/26;
    }
    r[index]='\0';
    reverse(r,index);
    return r;
}