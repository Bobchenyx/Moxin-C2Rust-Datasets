char res[5103] = {'\0'};
char * addStrings(char * num1, char * num2){
    short s1 = strlen(num1), s2 = strlen(num2), len = 5101, carry = 0;
    for (s1--, s2--; s1 >= 0 || s2 >= 0 || carry;) {
        carry += (s1 >= 0 ? num1[s1--] - 48: 0) + (s2 >= 0 ? num2[s2--] - 48 : 0);  // 最长遍历处理
        res[len--] = carry % 10 + 48;
        carry /= 10;
    }
    return &res[len+1];  // 返回指针，取地址
}