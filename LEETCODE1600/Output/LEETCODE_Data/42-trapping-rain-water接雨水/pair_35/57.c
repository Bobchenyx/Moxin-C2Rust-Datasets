#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

int trap(int *height, int heightSize)
{
    int *sort = NULL;
    sort = malloc((heightSize + 1) * sizeof(int));
    if (sort == NULL) {
        return 0;
    }

    memset(sort, 0x0, (heightSize + 1) * sizeof(int));
    int pos;
    int find;
    pos = 0;
    find = 0;
    while (find < heightSize) {
        int cur;
        cur = 0;
        pos = find;
        for (int index = pos + 1; index < heightSize; index++) {
            if (height[index] >= height[pos]) {
                find = index;
                break;
            } else if (height[index] > cur) {
                cur = height[index];
                find = index;
            }
        }

        if (find == pos) {
            find++;
            continue;
        }
        sort[pos] = find;
    }

    int area;
    area = 0;
    for (int left = 0; left <= pos; left++) {
        if (sort[left] == 0) {
            continue;
        }

        //printf("\r\n left =%d,right=%d,[%d->%d]", left, sort[left], height[left], height[sort[left]]);
        if (sort[left] - left - 1 <= 0) {
            continue;
        }

        int remove;
        remove = 0;
        for (int right = left + 1; right < sort[left]; right++) {
            remove += height[right];
        }

        area += ((sort[left] - left - 1) * MIN(height[sort[left]], height[left]) - remove);
    }
    return area;
}