class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        for (int num: nums) mp[num]++;

        int ans = 0, mx = 0;
        for (auto e: mp) {
            if (e.second > mx) {
                mx = e.second;
                ans = e.first;
            }
        }
        
        return ans;
    }
};
