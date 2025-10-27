/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){

    int *pRet = NULL;
    int iLeftIndex = 0;
    int iRightIndex = 0;
    int iMidIndex = 0;
    int iBool = 0;
    int iBoolLeft = 0;
    int iBoolRight = 0;

    pRet = (int *)malloc(sizeof(int) * 2);
    pRet[0] = -1;
    pRet[1] = -1;
    *returnSize = 2;

    iLeftIndex = 0;
    iRightIndex = numsSize - 1;
    while (iLeftIndex <= iRightIndex)
    {
        iMidIndex = (iLeftIndex + iRightIndex) / 2;
        if (nums[iMidIndex] == target)
        {
            iBool = 1;
            break;
        }

        if (nums[iMidIndex] < target)
        {
            iLeftIndex = iMidIndex + 1;
        }
        else
        {
            iRightIndex = iMidIndex - 1;
        }
    }

    if (1 == iBool)
    {
        iLeftIndex = iMidIndex;
        iRightIndex = iMidIndex;
        pRet[0] = iLeftIndex;
        pRet[1] = iRightIndex;
        while (1)
        {
            if ((iLeftIndex > 0) && 
                (target == nums[iLeftIndex - 1]))
            {
                iLeftIndex--;
            }
            else
            {
                pRet[0] = iLeftIndex;
                iBoolLeft = 1;
            }

            if ((iRightIndex < (numsSize - 1)) && 
                (target == nums[iRightIndex + 1]))
            {
                iRightIndex++;
            }
            else
            {
                pRet[1] = iRightIndex;
                iBoolRight = 1;
            }

            if ((1 == iBoolLeft) && (1 == iBoolRight))
            {
                break;
            }
        }
    }

    return pRet;
}