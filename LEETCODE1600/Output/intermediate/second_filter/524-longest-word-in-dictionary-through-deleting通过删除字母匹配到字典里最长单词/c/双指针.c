char * findLongestWord(char * s, char ** d, int dSize)
{
    char *result = "";      //g如果为空则输出此
    int len = -1;
    for(int i = 0; i<dSize ; i++)
    {   
        char *p = s;  char *q = d[i];
        int x= 0,y= 0;
        while(p[x] !='\0' && q[y] != '\0')    //判断是否是子串
        {
            if(p[x] == q[y])
            {
                x++;
                y++;
            }
            else
                x++;
        }
        if(q[y] == '\0')        //是子串就计入 result   
        {
            if(y>len)           //判断最符合结果的
            {
                len = y;
                result = q;
            }
            else if(len == y && q[0] - result[0] <0)
            {
               result = q;
            }
        }
    }
    return result;
}