class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto iter = lower_bound(nums.begin(), nums.end(), target);
        if(iter == nums.end() || *(iter) != target)
            return -1;
        else
            return iter - nums.begin();
    }
};
