class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return {-1, -1};

        auto lit = lower_bound(nums.begin(), nums.end(), target);
        auto uit = --lower_bound(nums.begin(), nums.end(), target+1);
        
        if(lit != nums.end() && *lit == target)
            return {(int) (lit - nums.begin()), (int) (uit - nums.begin())};
        else
            return {-1, -1};
    }
};
