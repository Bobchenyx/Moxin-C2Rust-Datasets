class Solution {
public:
    string compressString(string S) {
        int cnt=0;
        string r;
        for(int i=0; i<S.size(); i++){
            cnt++;
            if(S[i]!=S[i+1]){
                r.push_back(S[i]);
                r+=to_string(cnt);
                cnt=0;
            }
        }
        if(r.size()<S.size())
            return r;
        return S;
    }
};