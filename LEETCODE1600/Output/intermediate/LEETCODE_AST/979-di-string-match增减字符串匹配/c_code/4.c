/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char * S, int* returnSize){
    int a=0;
    int b=strlen(S);
    int n=b;
    int* num=(int*)malloc(sizeof(int)*(strlen(S)+1));
    for(int i=0;i<strlen(S);i++)
    {
        if(S[i]=='I')
        num[i]=a++;
        else
        num[i]=b--;
    }
    if(a==b)
    num[n]=a;
    *returnSize=strlen(S)+1;
    return num;
}