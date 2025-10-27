/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char * seq, int* returnSize){
    int length=0;
    for(int i=0;seq[i]!='\0';++i)++length;
    int* result=(int*)malloc(sizeof(int)*length);

    int depth=0;
    for(int i=0;i<length;++i)
    {
        if(seq[i]=='(')
            result[i]=depth++;
        if(seq[i]==')')
            result[i]=--depth;
        result[i]%=2;
    }
    *returnSize=length;
    return result;
}