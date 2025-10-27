//  有必要说明，该程序只会找到第一个满足条件的子串输出。
//  假如字符串中存在两个长度相等的最长不重复子串，该程序输出前一个

int lengthOfLongestSubstring(char * s)
{
    int tag[128] = {0};     //开辟一个数组，用来标记字符是否出现过
    int tag_index = 0;         
    int max = 0, sublen = 0;   

    for (int left = 0, right = 0; s[right] != '\0'; right++)
    { 
        tag_index = (int) (s[right]);    //用对应字符ASCII码做标记数组的下标
        if (tag[tag_index] > left)     //这个判断是为了保证left指针不能回退，
        {                              //同时，如果tag数组值大于left，也说明字符出现过了
            left = tag[tag_index];
        }
        tag[tag_index] = right + 1; 
        
        sublen = right - left + 1;
        if (max < sublen)
        {
            max = sublen;
//            start = left;         //这两句是用来记录最终结果的子串起始位置和结束位置
//            end = right;
        }
    }
    return max;
}