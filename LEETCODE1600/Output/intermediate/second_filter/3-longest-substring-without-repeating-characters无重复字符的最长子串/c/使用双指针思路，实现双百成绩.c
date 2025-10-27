#define ASCCI_SIZE 256

#define MAX(a, b) ((a) > (b) ? (a) : (b))
int lengthOfLongestSubstring(char *s)
{
    int bit[ASCCI_SIZE + 1];
    int end;
    int len;

    end = 0;
    len = 0;
    memset(bit, 0x0, sizeof(bit));
    for (int index = 0; s[index] != '\0'; index++) {
        end = MAX(end, index);
        for (; s[end] != '\0'; end++) {
            if (bit[s[end]] != 0) {
                break;
            }
            bit[s[end]] = 1;
        }
        bit[s[index]] = 0;
        len = MAX(len, (end - index));
    }
    return len;
}