int findLUSlength(char * a, char * b){
    if(!strcmp(a,b))
        return -1;
    return strlen(a)>strlen(b)? strlen(a):strlen(b);

}
Python:
return max(len(a), len(b)) if a!=b else -1