/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int i=0;
    int j=numbersSize-1;
    int *a=(int *)malloc(sizeof(int)*2);
    while(i<j)
    {
        if((numbers[i]+numbers[j])==target)
        {
            a[0]=i+1;
            a[1]=j+1;
            *returnSize = 2;
            break;
        }
        else if((*(numbers+i)+*(numbers+j)) > target)
        {
            j--;
        }
        else if((*(numbers+i)+*(numbers+j)) < target)
        {
            i++;
        }
    }
    if(i<j)
    {
        
        return a;
    }
    else{
        return NULL;
    }
    
}