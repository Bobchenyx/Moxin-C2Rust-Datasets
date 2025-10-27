int trap(int* height, int heightSize)
{
    int i, j = 0;
    int iLeft = 0;
    int iRight = 0;
    int iRightHigh = 0;
    int iMinHigh = 0;
    int iCnt = 0;
    int iTotalCnt = 0;

    for (i = 0; i < heightSize - 1; )
    {
        iLeft = i;
        iRight = i;
        iRightHigh = 0;
       
        i++;
        while (1)
        {   
            /* 寻找到下一个不低于左柱的右柱，直接返回 */
            if (height[i] >= height[iLeft])
            {
               iRight = i;
               break;
            }
           
            /* 记录右侧目前找到的最高柱 */
            if (height[i] > iRightHigh)
            {
                iRightHigh =  height[i];
                iRight = i; 
            }