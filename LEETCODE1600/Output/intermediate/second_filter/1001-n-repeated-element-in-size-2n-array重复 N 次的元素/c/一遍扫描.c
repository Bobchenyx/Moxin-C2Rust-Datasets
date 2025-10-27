class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int nSize = A.size();
        if (nSize == 0)
            return 0;
        int nTag = A[0];
        int nLast = A[1];
        for (int i = 2; i < nSize; ++i){
            int nTmp = A[i];
            if (nTmp == nTag || nTmp == nLast)
                return nTmp;
            else{
                nTag = nLast;
                nLast = nTmp;
            }
        }
        return nLast;
    }
};