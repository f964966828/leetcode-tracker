class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool incre = (nums[0] <= nums[n-1]);
        for(int i=1; i<n; i++){
            if(nums[i-1] == nums[i]) continue;
            if((nums[i-1] < nums[i]) ^ incre)
                return false;
        }

        return true;
    }
};
