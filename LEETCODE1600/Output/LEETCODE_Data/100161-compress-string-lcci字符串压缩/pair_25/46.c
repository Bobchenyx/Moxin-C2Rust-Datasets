char* compressString(char* S){
    int len = strlen(S);
    if(len < 3){
        return S;
    }

    int i, j;
    char* C = (char*)malloc(sizeof(char)*(2*len+1));
    memset(C, 0, sizeof(char)*(2*len+1));

    for(i=0, j=0; i<len; i++){
        if(S[i] != S[j]){
            sprintf(C, "%s%c%d",C,S[j],i-j);
            j = i;
        }
    }
    sprintf(C, "%s%c%d",C,S[j],i-j);

    if(strlen(C) < len){
        return C;
    }else{
        return S;
    }
}