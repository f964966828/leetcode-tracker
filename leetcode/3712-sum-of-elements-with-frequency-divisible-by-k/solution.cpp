class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        for (int & num : nums) ump[num]++;

        int ans = 0;
        for (auto & [key, val] : ump) ans += (val % k == 0) * key * val;
        return ans;
    }
};
