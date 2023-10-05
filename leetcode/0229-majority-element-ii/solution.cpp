class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for (auto num: nums) {
            mp[num]++;
        }
        
        vector<int> ans;
        for (auto e: mp) {
            if (e.second > n/3) {
                ans.push_back(e.first);
            }
        }
        return ans;
    }
};
