c [groups1-c直观双指针]
#define MAX_CHAR_TYPES 256

int lengthOfLongestSubstring(char *s)
{
    int count[MAX_CHAR_TYPES] = {0};
    int left, right;
    int len = strlen(s);
    int longest = 0;
    int subStrLen = 0;
    left = 0;
    right = 0;
    while (right < len) {
        // 右侧移动, 找到第一个重复字符;
        while (right < len) {
            count[s[right]]++;
            if (count[s[right]] > 1) {
                break;
            }
            subStrLen += 1;
            right += 1;
        }

        if (longest < subStrLen) {
            longest = subStrLen;
        }
        if (right == len) {
            // 已经检查完整个字符串
            break;
        }

        // 左侧移动, 保证记录的是不含重复字符的子串;
        while (left < right) {
            count[s[left]]--;
            if (count[s[left]] == 1) {
                left += 1;
                break;
            }
            left += 1;
            subStrLen -= 1;
        }
        right += 1;
    }
    return longest;
}