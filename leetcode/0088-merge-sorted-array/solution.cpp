class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i1 = 0, i2 = 0;
        while(i1 != m || i2 != n){
            if(i1 == m){
                ans.push_back(nums2[i2++]);
            }else if(i2 == n){
                ans.push_back(nums1[i1++]);
            }else if(nums1[i1] < nums2[i2]){
                ans.push_back(nums1[i1++]);
            }else{
                ans.push_back(nums2[i2++]);
            }
        }
        nums1 = ans;
    }
};
