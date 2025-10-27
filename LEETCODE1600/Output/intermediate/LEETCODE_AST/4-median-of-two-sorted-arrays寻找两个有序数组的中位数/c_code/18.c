c++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> tmp;
        int i = 0, j = 0;
        double median;
        
        int media_id = (nums1.size() + nums2.size()) / 2;
        
        if (nums1.size() == 0) {
            if (nums2.size() % 2)
                return (double) nums2[nums2.size() / 2];
            else
                return (double) (nums2[nums2.size() / 2 - 1] + nums2[nums2.size() / 2]) / 2;
        }
        
        if (nums2.size() == 0) {
            if (nums1.size() % 2)
                return (double) nums1[nums1.size() / 2];
            else
                return (double) (nums1[nums1.size() / 2 - 1] + nums1[nums1.size() / 2]) / 2;
        }
        
        while (i < nums1.size() && j < nums2.size() && tmp.size() <  (media_id + 1)) {        
            if (nums1[i] > nums2[j]) {
                tmp.push_back(nums2[j++]);
            } else {
                tmp.push_back(nums1[i++]);
            }     
        }
        
        if (tmp.size() > median) {
        for (; i < nums1.size(); i++) {
            tmp.push_back(nums1[i]);
        }
        
        for (; j < nums2.size(); j++) {
            tmp.push_back(nums2[j]);
        }
        }
        
        if ((nums1.size() + nums2.size()) % 2)
            median = (double)tmp[media_id];
        else
            median = ((double) tmp[media_id] + (double)tmp[media_id - 1]) / 2;
        
        return median;
    }
};