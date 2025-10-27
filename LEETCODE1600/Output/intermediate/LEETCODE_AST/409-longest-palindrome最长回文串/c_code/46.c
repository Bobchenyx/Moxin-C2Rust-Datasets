int longestPalindrome(char * s){
     int alphabet[58] = {0};
     int i, flag=0, res=0;
     // 记录每个字母的个数
     for(i=0; i<strlen(s); i++){
         alphabet[s[i]-'A']++;
     }
     // 遍历记录表，计算可以回文的数量
     for(i=0; i<58; i++){
         // 偶数个字母都可以作为回文字符用；奇数个字母则减去1后可以作为回文字符用，最后在加1（只加1次）
         if(alphabet[i]%2 == 0){
             res += alphabet[i];
         }else{
             flag = 1;
             res += alphabet[i]-1;
         }
     }
     return res+flag;
}