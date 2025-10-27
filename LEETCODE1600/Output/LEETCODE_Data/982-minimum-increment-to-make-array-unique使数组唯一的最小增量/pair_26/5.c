class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size() == 0)
            return 0;

        int nums [50100];
        for(int i = 0 ; i < 50100; i++)
            nums[i] = 0;
        
        for(int i = 0 ; i < A.size(); i++)
            nums[A[i]]++;
        
        int move = 0;
        for(int i = 0 ; i < A.size(); i++)
            if(nums[A[i]] != 1)
            {
                for(int j = A[i]; j < 50100; j++)
                    if(nums[j] == 0)
                    {
                        move += j - A[i];
                        nums[A[i]]--;
                        nums[j] = 1;
                        break;
                    }
            }

        return move;
    }
};