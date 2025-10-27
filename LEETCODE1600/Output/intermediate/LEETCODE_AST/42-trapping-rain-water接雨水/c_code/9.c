int trap(int* height, int heightSize){
    int * left = &height[0];               // 待求解区域左边界
    int * right = &height[heightSize - 1]; // 待求解区域右边界
    int * cl = left + 1;          // 左指针
    int * cr = right - 1;         // 右指针
    int ret = 0;                // 返回值

    while (cl <= right && cr >= left) {
        // 如果右边界较矮则移动右指针
        if (*left > *right) {
            // 当右指针移动到比右边界高的位置时
            // 认为右指针与右边界之间形成了一个坑
            if (*cr >= *right) {
                // 水面高度等于右指针和右边界中的较小值
                // 水面宽度等于 right - cr - 1
                ret += *right * (right - cr - 1);
                // 更新右边界
                right = cr;
            }
            else
                // 减去坑底的高度
                ret -= *cr;
            // 移动右指针
            --cr;
        }
        // 如果左边界较矮则移动左指针
        else {
            if (*cl >= *left) {
                ret += *left * (cl - left - 1);
                left = cl;
            }
            else
                ret -= *cl;
            ++cl;
        }
    }
    return ret;
}