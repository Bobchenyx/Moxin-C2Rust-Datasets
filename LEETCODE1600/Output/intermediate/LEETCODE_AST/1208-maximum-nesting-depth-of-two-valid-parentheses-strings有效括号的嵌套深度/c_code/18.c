/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char * seq, int* returnSize){
    int *deep;
    int i,tmp,max;
    tmp=0;max=0;
    for(i=0;seq[i];i++);
    deep=(int *)malloc(sizeof(int)*(i));
    for(i=0;seq[i];i++){
        if(seq[i]=='('){
            deep[i]=tmp;
            tmp++;
        }
        else{
            // tmp--;
            deep[i]=(--tmp);
        }
        max=(max>tmp)?max:tmp;
    }
    for(i=0;seq[i];i++){
        // printf("%d",deep[i]);
        if(deep[i]<max/2) deep[i]=0;
        else deep[i]=1;
    }
    *returnSize=i;
    return deep;
}