class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        int i1=0, i2=0;
        while(i1!=nums1.size() || i2!=nums2.size()){
            if(i1 == nums1.size()){
                nums3.push_back(nums2[i2++]);
            }else if(i2 == nums2.size()){
                nums3.push_back(nums1[i1++]);
            }else if(nums1[i1] < nums2[i2]){
                nums3.push_back(nums1[i1++]);
            }else if (nums1[i1] >= nums2[i2]){
                nums3.push_back(nums2[i2++]);
            }
        }

        int s = nums3.size();
        if(s%2){
            return (double)nums3[s/2];
        }else{
            return ((double)nums3[s/2-1] + (double)nums3[s/2])/2;
        }
    }
};
