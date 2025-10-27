/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//确定元素最终位置
 int Partition(int* nums, int low, int high){
     int pivot=nums[low];
     while(low<high){
         while(low<high && nums[high]>=pivot) --high;
         nums[low]=nums[high];
         while(low<high && nums[low]<=pivot) ++low;
         nums[high]=nums[low];
     }
     nums[low]=pivot;
     return low;
 }
//递归进行排序，并且查看pivotpos是否大于等于k
 void QuickSort(int *nums, int low, int high, int k){
     if(low<high){
         int pivotpos=Partition(nums,low,high);
         if(pivotpos>=k){
             QuickSort(nums,low,pivotpos-1,k);
         }
         else{
             QuickSort(nums,low,pivotpos-1,k);
             QuickSort(nums,pivotpos+1,high, k);
         }
     }
 }
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    QuickSort(arr,0,arrSize-1,k-1);
    (*returnSize)=k;
    return arr;
}