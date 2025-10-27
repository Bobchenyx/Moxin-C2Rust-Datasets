char* reversestr(char*s, int start, int end)
{
    int temp;
    while(start<end)
    {
        temp=s[end];
        s[end--]=s[start];
        s[start++]=temp;
    }
    return s;
}
char * reverseWords(char * s){
    while(*s==' ')//先去掉字串首的空格
    {
        s++;
        //printf("skip this blank\n");
    }
    int len=strlen(s);//重新计算去掉字串头的空格后的字符长度
    //冒泡去除多余的空格，比较耗时
    int cnt_blank=0;
    for(int i=0;i<len-1;i++)
    {
        if(s[i]==' ')
            cnt_blank++;
        if(s[i]==' ' && s[i+1]!=' ')//空格和有效字符的分界处
        {
            
            if(cnt_blank>1)//清除多余的空格
            {
                int exchange;
                for(int n=0;n<cnt_blank-1;n++)//移位cnt_blank-1
                    for(int k=(i+1)-n;k<len-n;k++)//每次移位的首下标 (i+1)-n
                    {
                        exchange=s[k];//第一个有效字符k=i-1
                        s[k]=s[k-1];
                        s[k-1]=exchange;
                    }
                i=i-cnt_blank-1;//后面整体迁移cnt_blank-1个字符，所以遍历的下标i也应该重新回到空格和有效字符的分界处
                len=strlen(s);
                cnt_blank=0;
            }
            else if(cnt_blank==1)
            {
                //skip this ONLY 1 blank
                cnt_blank=0;
            }
        }
    }
    printf("%s\n",s);
    //整体翻转，再每个单词翻转
    s=reversestr(s,0,len-1);
    while(*s==' ')//去掉翻转后字串首的空格，即刚开始尾部的空格
    {
        s++;
        //printf("skip this blank\n");
    }
    len=strlen(s);//重新计算去掉字串头的空格后的字符长度
    int start=-1,end=-1;//子单词的首尾标志
    //printf("%s\n",s);
    for(int i=0;i<=len;i++)//保证结束符也能参与比较
    {
        if(s[i]!=' ' && start<0)
        {
            start=i;
        }
        else if((s[i]==' ' || s[i]=='\0') && end<0 && start>=0)
        {
            end=i-1;
        }
        //printf("start: %d\n",start);
        //printf("end: %d\n",end);
        if(start>=0 && end >=0)//单词的首尾都已找到，可以翻转，反转后将首尾标志清除
        {
            s=reversestr(s,start,end);
            start=-1;
            end=-1;
        }
    }
    return s;
}