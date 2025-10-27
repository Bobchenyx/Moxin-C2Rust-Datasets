//copy大佬   算法太巧妙了
int lengthOfLongestSubstring(char * s){

    int N=strlen(s);
    int start=0;//相当于左指针，一开始在最左边的左边
    int end=1;//相当于右指针，一开始在第一个位置
    int asc[256]={0};//ASCII码对应数组
    int i;
    int max=0;
    //for(int i=0;i<N;i++)
    //{


    //}
    while(*s!='\0')
    {
        i=*s-0;//得到对应字母的ASCII码
        if(start<asc[i])
        {
            start=asc[i];//如果比他小，说明asc[i]中原来有过值了，说明前面出现过这个字母
        }
        asc[i]=end;
        max=(max>end-start)?max:end-start;//一点点动态规划
        s++;
        end++;
    }

    return max;
}