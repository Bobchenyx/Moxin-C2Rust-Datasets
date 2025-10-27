#include <stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i=0;//nums1的下标
    int j=0;//nums2的下标
    int k=0;
    int t[nums1Size];
    while(k<nums1Size){//曾写错为(k<nums1size && i<m && j<n)导致下面前两个if语句无法执行
        if(i==m){
            for(j,k;j<n,k<nums1Size;j++,k++){
                t[k]=nums2[j];
            }
            break;
        }
        if(j==n){
            for(i,k;i<m,k<nums1Size;i++,k++){
                t[k]=nums1[i];
            }
            break;
        }
        if(nums1[i]<nums2[j]){
            t[k++]=nums1[i++];
        }
        else{
            t[k++]=nums2[j++];
        }
    }
    for(i=0,k=0;i<nums1Size,k<nums1Size;i++,k++){
        nums1[i]=t[k];
    }
}