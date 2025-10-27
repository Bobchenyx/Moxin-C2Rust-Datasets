int removeDuplicates(int* nums, int numsSize){
    int i = 1;
    int *p,*pt;//声明的两个指针
    if(numsSize <= 1) return numsSize;//排除数组长度小1的数组
    p = pt = nums;
    for(;i < numsSize;i++) {
       if(*pt != *++pt)//当前指针pt指向的值不等于下一个指针指向的值时，执行下面语句
         *++p = *pt;  //将当前指针pt指向的值(注意上面的pt已经自增)赋值给p指针指向的位置 
    }
    return p - nums + 1;//由于p - t只算了差值没有算本身，所以需要加1
}