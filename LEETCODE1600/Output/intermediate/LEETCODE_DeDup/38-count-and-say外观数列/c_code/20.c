char * countAndSay(int n){
    char *res,*temp;
    res=malloc(sizeof(char)*5000);
    temp=malloc(sizeof(char)*5000);
    res[0]='1';
    res[1]='\0';
    int i,j,count;
    char *p,key;
    for(int i=1;i<n;i++)
    {
        j=0,count=0;
        p=res;
        key=res[0];
        while(*p!='\0')
        {
            if(*p==key)
                count++;
            else{
                temp[j++]=count+'0';
                temp[j++]=key;
                key=*p;
                count=1;
            }
            p++;
        }
        temp[j++]=count+'0';
        temp[j++]=key;
        temp[j]='\0';
        strcpy(res,temp);
    }
    return res;
}