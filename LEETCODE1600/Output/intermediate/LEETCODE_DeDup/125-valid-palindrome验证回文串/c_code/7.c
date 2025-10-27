char convert(char c){
    if(c>=65&&c<=90||c>=48&&c<=57) return c;
    else if(c>=97&&c<=122) return c - 32;
    else return '\0';  // 其他东西
}

bool isPalindrome(char * s){
    char lc,rc;
    for(short right=strlen(s)-1,left=0;left<right;left++,right--){
        while((lc=convert(s[left]))=='\0'&&left<right) left++;
        while((rc=convert(s[right]))=='\0'&&left<right) right--;
        if(lc!=rc) return false;
    }
    return true;
}