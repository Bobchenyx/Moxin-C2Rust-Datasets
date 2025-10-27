bool isValid(char * s){
    char stack[100000];
    int i=0,j=0;
    while(s[i]!='\0'){
        if(s[i]=='('||s[i]=='['||s[i]=='{'){
            stack[j++]=s[i];
        }else if(s[i]==')'){
            if(j-1<0||stack[j-1]!='('){
                return false;
            }else{
                j--;
            }
        }else if(s[i]==']'){
            if(j-1<0||stack[j-1]!='['){
                return false;
            }else{
                j--;
            }
        }else if(s[i]=='}'){
            if(j-1<0||stack[j-1]!='{'){
                return false;
            }else{
                j--;
            }
        }
        
        i++;
    }
    return !j;
}