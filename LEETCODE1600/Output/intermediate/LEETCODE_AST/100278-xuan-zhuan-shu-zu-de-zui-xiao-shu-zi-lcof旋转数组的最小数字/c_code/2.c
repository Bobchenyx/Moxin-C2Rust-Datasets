int minArray(int* numbers, int numbersSize)
{
    //入参检查
    if(!numbers)
    {
        return 0;
    }
    //查找数组的最小值
    int min = numbers[0];
    for(int i=0; i<numbersSize; i++)
    {
        if(min >= numbers[i])
        {
            min = numbers[i];
        }
    }
    return min;
}