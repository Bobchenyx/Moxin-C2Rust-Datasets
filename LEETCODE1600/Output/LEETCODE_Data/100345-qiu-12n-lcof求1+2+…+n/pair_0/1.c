class Solution {
public:
    int sumNums(int n) {
        // int ans=0;/
        n&&(n=sumNums(n-1)+n);
        return n;
    }
};