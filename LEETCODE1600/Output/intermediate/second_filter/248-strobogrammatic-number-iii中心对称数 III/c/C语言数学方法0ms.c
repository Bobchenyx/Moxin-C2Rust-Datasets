#include <stdbool.h>

static const int pair[] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
static const int mid[] = {0, 1, 8};
static const int head[] = {1, 6, 8, 9};
static const int other[] = {0, 1, 6, 8, 9};

static inline int str_to_array(char *str);
static inline int get_size(int n);
static int get_low_size(char *num, int n, bool contain_self);
int strobogrammaticInRange(char *low, char *high)
{
    int low_n = str_to_array(low);
    int high_n = str_to_array(high);
    if (low_n > high_n)
        return 0;

    int cnt = 0;
    for (int i = low_n; i < high_n; i++)
        cnt += get_size(i);

    cnt += get_low_size(high, high_n, true);
    cnt -= get_low_size(low, low_n, false);

    return cnt > 0 ? cnt : 0;
}

static inline int str_to_array(char *str)
{
    int i = 0;
    for (; str[i] != '\0'; i++)
        str[i] -= '0';
    return i;
}

static inline bool had_head(int n)
{
    return n / 2 >= 1;
}

static inline bool had_mid(int n)
{
    return n % 2 == 1;
}

static inline int get_other_digit(int n)
{
    int cnt = n / 2 - 1;
    return cnt > 0 ? cnt : 0;
}

static inline int my_pow(int base, int n)
{
    int result = 1;
    for (int i = 0; i < n; i++)
        result *= 5;
    return result;
}

static inline int get_size(int n)
{
    if (n == 0)
        return 0;
    int cnt = 1;
    cnt *= had_head(n) ? 4 : 1;
    cnt *= had_mid(n) ? 3 : 1;
    int other_digit = get_other_digit(n);
    return cnt * my_pow(5, other_digit);
}

static inline int get_low_cnt(const int *arr, int n, int target)
{
    int i = 0;
    for (; i < n && arr[i] < target; i++) ;
    return i;
}

static int get_low_size(char *num, int n, bool contain_self)
{
    int other_digit = get_other_digit(n);
    int all_mid = had_mid(n) ? 3 : 1;
    int cnt = 0;
    if (had_head(n)) {
        int low_head = get_low_cnt(head, sizeof(head) / sizeof(head[0]), num[0]);
        cnt += low_head * my_pow(5, other_digit) * all_mid;
        if (pair[num[0]] == -1) // 如果最高位不是对称数，则最高位是给定值时对称数为0
            return cnt;
    }

    // num[0]是给定值
    for (int i = 0; i < other_digit; i++) {
        int low_other = get_low_cnt(other, sizeof(other) / sizeof(other[0]), num[1 + i]);
        cnt += low_other * my_pow(5, other_digit - 1 - i) * all_mid;
        if (pair[num[1 + i]] == -1) // 如果当前位不是对称数，则当前位是给定值时对称数为0
            return cnt;
    }

    // 前几位都是给定值
    if (had_mid(n)) {
        int low_mid = get_low_cnt(mid, sizeof(mid) / sizeof(mid[0]), num[n / 2]);
        cnt += low_mid;
        if (pair[num[n / 2]] != num[n / 2]) // 如果中间位不是对称数，则中间位是给定值时对称数为0
            return cnt;
    }

    if (!contain_self)
        return cnt;

    for (int i = other_digit - 1; i >= 0; i--)
        if (num[n - 2 - i] < pair[num[1 + i]])
            return cnt;
    
    if (num[n - 1] < pair[num[0]])
        return cnt;

    return cnt + 1;
}