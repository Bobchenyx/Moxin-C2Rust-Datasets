/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define MAX(a,b) ((a)>(b)?(a):(b))
int* maxDepthAfterSplit(char * seq, int* returnSize){
    int len=strlen(seq),d=0,dmax=0;
    int *depth=(int *)calloc(len,sizeof(int));
    for(int i=0;i<len;i++)
    {
        if(seq[i]=='(')
        {

        d++;
        depth[i]=d;
        dmax=MAX(dmax,d);
        }
        else
        {
           depth[i]=d;
           d--; 
        }
    }
    int hdepth=dmax/2;
    for(int i=0;i<len;i++)
    {
        if(depth[i]<=hdepth)depth[i]=0;
        if(depth[i]>hdepth)depth[i]=1;
    }
    *returnSize = len;
    return depth;
}