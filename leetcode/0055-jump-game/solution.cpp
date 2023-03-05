class Solution {
public:
    bool canJump(vector<int>& nums) {

        if(nums.size() == 1) 
            return true;

        int step = nums[0], idx = 1;
        while(step){
            step = max(step-1, nums[idx++]);
            if(idx == nums.size()) 
                return true;
        }

        return false;
    }
};
