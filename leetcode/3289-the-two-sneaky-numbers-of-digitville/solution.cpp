class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int &num : nums) mp[num]++;

        vector<int> ans;
        for (auto &[key, val] : mp) {
            if (val == 2) ans.push_back(key);
        }

        return ans;
    }
};
