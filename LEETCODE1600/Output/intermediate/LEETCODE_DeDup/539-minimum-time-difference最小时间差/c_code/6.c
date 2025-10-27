#define TIME_NUM_MAX 1440

// 字符串转分钟
int time2int(char* time) 
{
    int h;
    int m;

    h = (time[0] - '0') * 10 + (time[1] - '0');
    m = (time[3] - '0') * 10 + (time[4] - '0');

    return h * 60 + m;
}

// 检查数组中最小的间隔
int checkarr(int* count_arr)
{
    int last_time = -1;
    int i;
    int min_time = TIME_NUM_MAX;
    int cur_time;

    for (i = 0; i < TIME_NUM_MAX * 2; ++i) {
        if (count_arr[i] == 1) {
            if (last_time != -1) {
                cur_time = i - last_time;
                if (min_time > cur_time) {
                    min_time = cur_time;
                }
            }
            last_time = i;
        }
    }

    return min_time;
}

int findMinDifference(char ** timePoints, int timePointsSize){
    int count_arr[TIME_NUM_MAX * 2] = {0};
    int i;
    int tmp;

    if (timePointsSize >= TIME_NUM_MAX) {
        return 0;
    }

    for (i = 0; i < timePointsSize; ++i) {
        tmp = time2int(timePoints[i]);
        if (count_arr[tmp] == 1) {
            return 0;
        } else {
            count_arr[tmp]++;
            count_arr[tmp + TIME_NUM_MAX]++;
        }
    }

    return checkarr(count_arr);
}