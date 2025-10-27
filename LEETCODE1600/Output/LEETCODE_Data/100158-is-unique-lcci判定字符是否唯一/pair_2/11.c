//解法一代码实现
bool isUnique(char* astr)
{
    bool rel = true;
    //入参检查
    if(strlen(astr) == 0)
    {
        rel = true;
    }
    else
    {
        //建立整形数组
        int len = strlen(astr);
        int arr[len];

        //将字符串转换为字符数组
        for(int i=0; i<len;i++)
        {
            arr[i] = astr[i] - 'a';
        }

        //利用桶排序
        int bucket[26] = {0};
        for(int j=0; j<len;j++)
        {
            bucket[arr[j]]++;
        }
        //遍历整形数组中各元素是否存在大于1的元素
        for(int k=0;k<26;k++)
        {
            if(bucket[k] >1)
            {
                rel = false;
                break;
            }
        }
    }
    return rel;
}