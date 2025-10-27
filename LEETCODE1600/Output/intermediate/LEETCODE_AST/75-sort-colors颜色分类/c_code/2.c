void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void sortColors(int* nums, int numsSize){
    int i=0;
    int j=numsSize-1;
    int cur=0;
    while(cur<=j){
        if(nums[cur]==0){
            swap(&nums[i],&nums[cur]);
            i++;
            cur++;
        }
        else if(nums[cur]==2){
            swap(&nums[j],&nums[cur]);
            j--;
        }
        else
            cur++;
        
    }
}