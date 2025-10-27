bool isPalindrome(char * s){
    bool flag = true;
    int len = 0;
    int cnt = 0;
    while (s[len]!='\0') {
        if (('a'-1<s[len]&&s[len]<'z'+1)||
            ('A'-1<s[len]&&s[len]<'Z'+1)||
            ('0'-1<s[len]&&s[len]<'9'+1))
            cnt++; //该字符串中字母和数字的长度 
        len++; //该字符串的总长度 
    }

    int cnt_copy = cnt;
    char *p = (char*)malloc(sizeof(char)*(cnt+1)); //字符串一定要多一个字符保存'\0' 
    char *q = p;
    while (len>0) {
        if (('a'-1<s[len-1]&&s[len-1]<'z'+1)||
            ('0'-1<s[len-1]&&s[len-1]<'9'+1))
            *q++ = s[len-1];
        
        if ('A'-1<s[len-1]&&s[len-1]<'Z'+1)
            *q++ = s[len-1]+('a'-'A');
        len--;
    }
    *q = '\0';

    cnt /= 2;
    while (cnt>0) {	
        //如果对应位置的字符不相同 
        if (p[cnt-1]!=p[cnt_copy-cnt]) {
            flag = false;
            break;
		}	
        cnt--;
    }
    free(p);
    return flag;
}