/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    int *nums = (int *)calloc(num_people, sizeof(int));
    int offset = 0;
    while (candies != 0) {
        for (int i = 0; i < num_people; i++) {
            if (candies > offset + i + 1) {
                nums[i] += offset + i + 1;
                candies -= offset + i + 1;
            }
            else {
                nums[i] += candies;
                candies = 0;
                break;
            }    
        }
        offset += num_people;
    }
    *returnSize = num_people;
    return nums;
}