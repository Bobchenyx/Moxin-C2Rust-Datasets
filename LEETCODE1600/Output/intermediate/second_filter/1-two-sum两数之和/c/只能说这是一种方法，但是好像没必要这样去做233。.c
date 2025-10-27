/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
  struct Sqlist{
     int *data;
     int length;
 }*L1;
 typedef struct Sqlist Sqlist;
void CreatList(Sqlist **L,int *nums,int n){
     int i;
     *L=(Sqlist*)malloc(sizeof(Sqlist)*1);
     (**L).data=(int*)malloc(sizeof(int)*n);
     for(i=0;i<n;i++)
     {
        (**L).data[i]=nums[i];
     }
     (**L).length=n;
     return ;
 }
 int GetElem(Sqlist *L,int n,int target)
 {
     int i;
     for(i=n+1;i<(*L).length;i++)
     {
         if((*L).data[i]==target) 
         {
             return i;
             break;
         }
     }
     return 0;
 }
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    CreatList(&L1,nums,numsSize);
    int i;int k;int *arr;
    arr=(int*)malloc(sizeof(int)*2);
    for(i=0;i<numsSize;i++)
    {
        k=GetElem(L1,i,target-nums[i]);
        if(k!=0) arr[0]=i,arr[1]=k;
    }
    free(L1);
    *returnSize=2;
    return arr;
}