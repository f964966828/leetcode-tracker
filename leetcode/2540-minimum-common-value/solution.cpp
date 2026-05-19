class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, n = nums1.size(), m = nums2.size();
        while (i != n && j != m && nums1[i] != nums2[j]) {
            if (nums1[i] < nums2[j]) i++;
            else j++;
        }
        
        if (i == n || j == m) return -1;
        else return nums1[i];
    }
};
