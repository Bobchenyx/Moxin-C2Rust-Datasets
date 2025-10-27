bool isValid(char * s){
    int n=strlen(s);
    char str[++n];
    int i=0,top=-1;
    if(s[0]=='\0')
    return true;
    while(s[i]!='\0')
    {   
        
        switch(s[i])
        {
            case '(':top++;str[top]=s[i];i++;break;
            case '[':top++;str[top]=s[i];i++;break;
            case '{':top++;str[top]=s[i];i++;break;
            case ')':
                if(top==-1) return false;
                if(str[top]!='(') return false;
                else
                {
                    str[top]='\0';
                    top--;
                    i++;
                    break;
                }
            case ']':
                if(top==-1) return false;
                if(str[top]!='[') return false;
                else{
                    str[top]='\0';
                    top--;
                    i++;
                    break;
                }
            case '}':
                if(top==-1) return false;
                if(str[top]!='{') return false;
                else{
                    str[top]='\0';
                    top--;
                    i++;
                    break;
                }
        }
    }
    if(top==-1) return true;
    else {return false;}
}