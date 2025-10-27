bool isValid(char * s){
char* stack=(char*)calloc(strlen(s)+1,sizeof(char));
int top=-1;

for(int i=0;s[i]!='\0';i++){
    if(s[i]=='('||s[i]=='['||s[i]=='{'||top==-1){
        stack[++top]=s[i];
    }
    else if(s[i]==stack[top]+1||s[i]==stack[top]+2){
        --top;
    }
    else {return false;}
}
return top==-1?true:false;
}