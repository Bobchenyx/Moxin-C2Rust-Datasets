void sortColors(int* nums, int numsSize)
{
    if (nums==NULL && numsSize<=0)
    {
        return;
    }
    
    int cur = 0; //工作指针cur
    int* p = nums; //指向nums的数组
    int left_two = numsSize-1; 
    int right_zero = 0; 
    
    while (cur <= left_two) //cur一定要对left_two所指向的值进行检验，注意通过下面的代码体会为什么
    {
        if (p[cur] == 1)
        {
            ++cur; //将1留在中间，cur可以直接前进
        }
        else if (p[cur] == 0)
        {
           int temp = p[right_zero]; 
            p[cur] = temp; 
            p[right_zero] = 0; //使right_zero指向最右侧的0
            
            right_zero++; 
            cur++; // 此时不用担心right_zero所指向的值非0，因为随着cur的遍历会对right_zero的指向进行调整
        }
        else 
        {
            int temp = p[left_two]; 
            p[cur] = temp; 
            p[left_two] = 2; 
            
            left_two--; //原先left_two已指向2，要让它指向最左边的2，后移；此处理解务必cur<=left_two的原因
        }
    }
    
    return;
}