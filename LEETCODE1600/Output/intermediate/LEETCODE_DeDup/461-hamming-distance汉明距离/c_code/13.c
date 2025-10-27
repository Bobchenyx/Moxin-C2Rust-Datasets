class Solution {
public:
    int hammingDistance(int x, int y) {
        int tmp = x ^ y;
        int num = 0;
        for(int i=0;i<32;i++)
        {
            if(tmp & (1<<i))
                num++;
        }
        return num;
    }
};