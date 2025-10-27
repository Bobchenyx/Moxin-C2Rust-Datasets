int get(char *s,int t){
    char line[100000];
    int head=-1;
     int i=0;
     int max=0;
     int num=0;
     for(i=t;i>=0;i--){
         if(s[i]==')'){
             head++;num++;
             line[head]=s[i];
         }
         else{
             if(head>=0){
                 head--;num++;
             }
             else{
                  return max;
             }
         }
         if(head==-1){
            if(max<num)
                 max=num;
         }
     }
     return max;
}

int longestValidParentheses(char * s){
     
     int max=0;
     int i;
     for(i=0;i<strlen(s);i++){
         int t=get(s,i);
         if(max<t){
             max=t;
         }
     }
     return max;
}