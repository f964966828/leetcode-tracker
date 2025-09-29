class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int & num : nums) mp[num]++;
        
        int freq = 0;
        for (auto & [key, val] : mp) freq = max(freq, val);

        return freq * k <= nums.size();
    }
};
