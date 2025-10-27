char * gcdOfStrings(char * str1, char * str2){
    int i=0,j=0,m=0,n=0,sum=0; 
    while(str1[i]!='\0' && str2[j]!='\0'){
        sum = 0;
        while(str1[i]!='\0' && str2[j]!='\0'){
            if(str1[i] != str2[j]){
                char* result = (char*)malloc(sizeof(char)*1);
                result[0] = '\0';
                return result;
            }
            sum++;
            i++;
            j++;
        }
        if(str1[i]=='\0' && str2[j]!='\0'){
            i = m;
            n = j;
        }else if(str1[i]!='\0' && str2[j]=='\0'){
            j = n;
            m = i;
        }
    }
    char* result = (char*)malloc(sizeof(char)*(sum+1));
    for(int k=0;k<sum;k++){
        result[k] = str1[k];
    }
    result[sum] = '\0';
    return result;  
}