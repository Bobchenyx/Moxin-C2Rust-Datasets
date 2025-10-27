void sortColors(int* nums, int numsSize){

    int zero_tail = 0;

    int one_tail = 0;

    int two_tail = 0;
    int Idx = 0;
    while (Idx < numsSize)
    { 
        // 如果遍历到0
        if (nums[Idx] == 0) {
            // 两者不相等，说明曾经扫描到2了，则将最前面的2换到最后面位置（为前面插0预留位置）
            if (one_tail != two_tail) {
                nums[two_tail] = 2;
            }

            // 两者不相等 说明曾经扫描到1了，将最前面的1换到1后面（也就是前面2空出来）的位置
            if (zero_tail != one_tail) {
                nums[one_tail] = 1;
            }

            //在0的后面插入0
            nums[zero_tail] = 0;  

            //所有的tail都往后移动1
            zero_tail++;
            one_tail++;
            two_tail++;      
        }
        else if (nums[Idx] == 1)  // 如果遍历到1
        {

            if (one_tail != two_tail)  //曾经扫描到过2，将2换到最后
            {
                nums[two_tail] = 2;
            }
            nums[one_tail] = 1;  // 1最后面（2最前面空出来的位置）插入1

            //1和2的tail都移动1
            one_tail++;
            two_tail++;
        }
        else // 如果是2,2的tail直接移动
        {
            two_tail++;
        }
        Idx++;
    }
    return;
}