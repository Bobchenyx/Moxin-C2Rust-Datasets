char * convert(char * s, int numRows){
    if(numRows == 1){
        return s;
    }
    int n=strlen(s),j,k=0;
    char *result = (char*)malloc(sizeof(char)*(n+1));
    result[n] = '\0';
    for(int i=0;i<numRows;i++){
        if(i==0 || i==numRows-1){               //第一行和最后一行
            for(j=i;j<n;j += 2*numRows-2){
                result[k++] = s[j];
            }
        }else{                                  //其余行
            for(j=i;j<n;j += 2*numRows-2){
                result[k++] = s[j];
                if(j+2*(numRows-1-i)<n){
                result[k++] = s[j+2*(numRows-1-i)];  
                }
            }
        }
    }
    return result;
}