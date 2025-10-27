/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    
    int *A = (int*)malloc(sizeof(int) * num_people);
    
    memset(A, 0, sizeof(int) * num_people);

    int i = 0;

    while((candies -= i++) && candies > 0)
    {
        A[(i-1)%num_people] += ((candies - i > 0) ? i : candies);
    }

    *returnSize = num_people;

    return A;
}