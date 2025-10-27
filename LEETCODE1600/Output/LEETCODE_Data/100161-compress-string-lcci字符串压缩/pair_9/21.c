class Solution {
public:
    string compressString(string S) {
        string res = "";
        int cnt = 1;

        for (int i = 1;i <= S.size(); i ++ ) {
            if (S[i] == S[i - 1]) cnt ++ ;
            else {
                res += S[i - 1] + to_string(cnt);
                cnt = 1;
            }
        }
        return res.size() >= S.size() ? S : res;
    }
};