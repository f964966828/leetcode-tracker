class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> mp;
        for (int num : nums) mp[num]++;
        
        int ans = 0;
        for (auto e : mp) {
            if (e.first * 2 == k) {
                ans += e.second / 2;
            } else if (e.first * 2 < k) {
                ans += min(e.second, mp[k - e.first]);
            }
        }

        return ans;
    }
};
