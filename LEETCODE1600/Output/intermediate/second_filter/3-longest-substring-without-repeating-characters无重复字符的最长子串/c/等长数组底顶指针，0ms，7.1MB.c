python3 []
def lengthOfLongestSubString(s):
    length = len(s)
    if length <= 1:
        return length
    lst, _max = [], 1
    for i in range(length):
        if s[i] in lst:
            _max = max(_max, len(lst))
            lst = lst[lst.index(s[i])+1:]
        lst.append(s[i])
    return max(_max, len(lst))