int wiggleMaxLength(int* nums, int numsSize){
    if (numsSize == 0)
    {
        return 0;
    }

    static const int BEGIN = 0;
    static const int UP = 1;
    static const int DOWN = 2;

    int state = BEGIN;
    int maxLength = 1;

    for (int i = 1; i < numsSize; i ++)
    {
        switch(state)
        {
            case BEGIN:
            {
                if (nums[i] > nums[i - 1])
                {
                    state = UP;
                    maxLength ++;
                }
                else if (nums[i] < nums[i - 1])
                {
                    state = DOWN;
                    maxLength ++;
                }
                break;
            }
            case UP:
            {
                if (nums[i] < nums[i - 1])
                {
                    state = DOWN;
                    maxLength ++;
                }
                break;
            }
            case DOWN:
            {
                if (nums[i] > nums[i - 1])
                {
                    state = UP;
                    maxLength ++;
                }
                break;
            }
            default :
                break;
        }
    }
    return maxLength;

}