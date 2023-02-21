class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0, r=nums.size()/2, ans;
        while(l<=r){
            int mid = (l+r)/2, idx=mid*2;
            if(idx+1 >= nums.size() || nums[idx] != nums[idx+1]){ 
                r = mid-1;
                ans = nums[idx];
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};
