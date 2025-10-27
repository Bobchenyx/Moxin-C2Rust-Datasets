char* readchar(char *input)//"111221"
{
    int len=strlen(input),count=1,i=0,j=0;
    char *output=malloc(5000);
    if(output==NULL)
    {
        printf("malloc error\n");
        exit(0);
    }
    for(i=0;i<len;i++)
    {
        if(input[i]==input[i+1])
        {
            count++;
        }
        else
        {
            output[j]=count+'0';
            j++;
            output[j]=input[i];
            j++;
            count=1;
        }
    }
    output[j]='\0';
    return output;
}
char * countAndSay(int n){
    if(n==1)
    {
        return "1";
    }
    if(n==2)
    {
        return "11";
    }
    if(n==3)
    {
        return "21";
    }
    if(n==4)
    {
        return "1211";
    }
    if(n==5)
    {
        return "111221";
    }
    return readchar(countAndSay(n-1));
}