/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* prefixesDivBy5(int* A, int ASize, int* returnSize){
    bool *answer = (bool*)malloc(sizeof(bool)*ASize);
    *returnSize = ASize;
    int temp = 0;
    for(int i = 0;i<ASize;i++){
        temp = temp*2+A[i];
        if(temp%5 == 0)
            answer[i] = true;
        else
            answer[i] = false;
        temp = temp%10;
    }
    return answer;
}