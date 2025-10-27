static inline void setMap(char *map, int i)
{
    int a = i >> 3;
    int b = i - (a << 3);
    map[a] = map[a] | (1 << b);
    return;
}
static inline bool isTrue(char *map, int i)
{
    int a = i >> 3;
    int b = i - (a << 3);
    return ((map[a] & (1 << b)) != 0);
}
int majorityElement(int* nums, int numsSize)
{
    if (numsSize == 1) return nums[0];
    int half = numsSize / 2;
    char *map = malloc(numsSize / 8 + 1);
    memset(map, 0, numsSize / 8 + 1);
    for (int i = 0; i < (numsSize - 1); i++) {
        if (isTrue(map, i)) {
            continue;
        }
        int x = nums[i];
        int count = 1;

        for (int j = i + 1; j < numsSize; j++) {
            if (x == nums[j]) {
                count++;
                setMap(map, j);
                if (count > half) {
                    return x;
                }
            }
        }
    }
    return 0;
}