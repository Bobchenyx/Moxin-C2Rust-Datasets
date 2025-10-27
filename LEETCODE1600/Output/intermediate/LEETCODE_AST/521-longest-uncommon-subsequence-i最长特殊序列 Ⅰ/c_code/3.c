int findLUSlength(char * a, char * b){
    int alen=strlen(a),blen=strlen(b);
    if (strcmp(a,b)==0)return -1;
        return alen>blen?alen:blen;
}