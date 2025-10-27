class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax = 0;
        int rightMax = 0;
        int ans = 0;
        int i = 0, j = height.size() - 1;
        while(i < j){
            while(i < j && height[i] <= height[i+1]){
                ++i;
            }
            while(i < j && height[j] <= height[j-1]){
                --j;
            }
            leftMax = height[i];
            rightMax = height[j];
            if(leftMax < rightMax){
                while(i < j && height[i] <= leftMax){
                    ans += leftMax - height[i];
                    ++i;
                }
            }
            else{
                while(i < j && height[j] <= rightMax){
                    ans += rightMax - height[j];
                    --j;
                }
            }
        }
        return ans;
    }
};