void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int final_index=m+n-1; //合并后数组的长度
    int nums1_index=m-1;  //nums1当前索引位置
    int nums2_index=n-1;  //nums2当前索引位置
    while(final_index>=0)
    {
        if((nums1_index>=0)&&(nums2_index>=0))
        {
            if(nums1[nums1_index]>nums2[nums2_index])            //nums1中的数字大放入最终位置
            {
                nums1[final_index--]=nums1[nums1_index--];
            }else{                                               //nums2中的数字大放入最终位置
                nums1[final_index--]=nums2[nums2_index--];
            }
        }else if(nums1_index<0){                                 //nums1中的已经全部放完放剩下的nums2
            nums1[final_index--]=nums2[nums2_index--];
        }else{                                                   //nums2中的已经全部放完nums1已经是有序的可以退出
            break;
        }
    }
    return 0;
}