#define MIN_SIZE 2
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int jump(int *nums, int numsSize)
{
    if (numsSize <= MIN_SIZE) {
        return MAX(numsSize - 1, 0);
    }

    int curPos = 0;
    int count = 0;
    int nextPos = nums[0];
    count++;
    for (int index = nextPos; (nextPos < numsSize - 1);) {
        count++;
        for (int pos = curPos + 1; pos <= nextPos; pos++) {
            index = MAX(index, nums[pos] + pos);
        }
        if (index == nextPos) {
            break;
        }
        
        curPos = nextPos;
        nextPos = index;
    }
    return MAX(count, 1);
}