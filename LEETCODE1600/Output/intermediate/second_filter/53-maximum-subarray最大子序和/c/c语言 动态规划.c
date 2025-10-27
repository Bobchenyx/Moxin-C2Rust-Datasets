#define MAX(a, b) ((a) > (b) ? (a) : (b))
int maxSubArray(int* nums, int numsSize){
   int dpmax = 0;
   int max = nums[0];
   for (int i = 0; i < numsSize; i++) {
       dpmax = MAX((dpmax + nums[i]), nums[i]);
       max = MAX(max, dpmax);
   }
    return max;
}