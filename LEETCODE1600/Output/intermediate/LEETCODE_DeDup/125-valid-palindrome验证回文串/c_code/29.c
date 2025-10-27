bool isPalindrome(char * s){
    int len=strlen(s);
    int left=-1;
    int right=len;
    if(len==0)
        return true;
    while(left<right)
    {
        while(1)
        {
            left++;
            //跳过非字母数字字符
            //注意先判断left与right的大小，否则可能后面s越界
            if(left>=right||(s[left]>='A'&&s[left]<='Z')||(s[left]>='a'&&s[left]<='z')||(s[left]>='0'&&s[left]<='9'))
                break;
        }
        while(1)
        {
            right--;
            //跳过非字母数字字符
            if(left>=right||(s[right]>='A'&&s[right]<='Z')||(s[right]>='a'&&s[right]<='z')||(s[right]>='0'&&s[right]<='9'))
                break;
        }

        if(left<right)
        {
            //left right都为数字
            if((s[left]>='0'&&s[left]<='9')&&(s[right]>='0'&&s[right]<='9'))
            {
                if(s[left]!=s[right])
                    return false;
            }
            //left right都为字母
            else if(((s[left]>='A'&&s[left]<='Z')||(s[left]>='a'&&s[left]<='z'))&&((s[right]>='A'&&s[right]<='Z')||(s[right]>='a'&&s[right]<='z')))
            {
                //left大于right情况
                if(s[left]>s[right])
                    //left不为right大写
                    if(s[left]-32!=s[right])
                        return false;
                //left小于right情况
                if(s[left]<s[right])
                    //left不为right小写
                    if(s[left]!=s[right]-32)
                        return false;
            }
            else 
                //一个数字一个字母的情况防止 "0P"
                return false;
        }
        else
            break;
    }

    return true;


}