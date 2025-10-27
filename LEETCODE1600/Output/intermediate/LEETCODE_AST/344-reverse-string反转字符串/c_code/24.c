class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty()) return;//判空输入
        int l=s.size()-1,k=l/2;
        char ch;
        for (int i=0; i <= k; i++) {
            if(s[l-i] == s[i]) continue;//判相同，对节省时间非常有帮助
            ch=s[l-i];
            s[l-i]=s[i];
            s[i]=ch;
            //调换位置
        }
    }
};