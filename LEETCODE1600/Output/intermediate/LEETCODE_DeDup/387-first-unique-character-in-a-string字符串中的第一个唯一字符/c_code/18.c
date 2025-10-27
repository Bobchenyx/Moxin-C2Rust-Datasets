/*暴力法超时
int firstUniqChar(char * s){
    int slen = strlen(s);
    int count;
    for(int i = 0; i < slen; i++)
    {
        count = 0;
        for(int j = 0; j < slen; j++)
        {
            if(s[i] == s[j])
                count++;
        }
        if(count == 1)
            return i;
        else
            continue;
    }
    return -1;
}*/


//哈希表
typedef struct{
    int val;
    int pos;
}map;

int firstUniqChar(char * s){
    int i, j;
    int slen = strlen(s);
    int min = slen;
    map *m = (map*)malloc(sizeof(map)*26);
    for(i = 0; i < 26; i++)
    {
        m[i].val = 0;
        m[i].pos = -1;
    }

    for(int i = 0; i < slen; i++)
    {
        m[s[i]-97].val++;
        m[s[i]-97].pos = i;
    }

    for(i = 0; i < 26; i++)
        if(m[i].val == 1 && m[i].pos < min)
            min = m[i].pos;
    
    if(min < slen)
        return min;
    else
        return -1;
}