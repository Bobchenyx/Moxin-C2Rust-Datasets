/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char * seq, int* returnSize){
    int i, depth=0, len=strlen(seq);
    int* nums = malloc(sizeof(int) * len);

    for(i=0; i<len; i++){
        if(seq[i] == '('){
            depth++;
            nums[i] = depth;
        }
        
        if(seq[i] == ')'){
            nums[i] = depth;
            depth--;
        }

        nums[i] = nums[i]%2;
    }

    *returnSize = len;
    return nums;
}