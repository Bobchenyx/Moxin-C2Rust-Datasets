bool isValid(char * s){
    
    int len=strlen(s);
    bool rtn=false;
    if(len==0)
        return true;

    char str[len];
    if(len%2!=0)
        rtn=false;
    else {
        for(int i=0;*s!='\0';s++,i++){
            if(*s=='('||*s=='['||*s=='{')
                str[i]=*s;
            else{
                i--;
                if(i<0)
                    rtn=false;
                else{
                switch (*s){
                    case ')':
                        if(str[i]=='('){
                            str[i]='\0';
                            i--;
                            rtn= true;
                        }else
                           return false;
                        break;
                    case ']':
                        if(str[i]=='['){
                            str[i]='\0';
                            i--;
                            rtn= true;
                        }else
                           return false;
                        break;
                    case '}':
                        if(str[i]=='{'){
                            str[i]='\0';
                            i--;
                            rtn= true;
                        }else
                           return false;
                        break;
                    default:
                       return false;
                }}
                
            }
            //else
            //  rtn=false;
        }

    }


    if(str[0]!='\0')
        rtn=false;

    return rtn;
}