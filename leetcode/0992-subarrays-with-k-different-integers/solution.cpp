class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, pos = 0, count = 0;
        map<int, pair<int, int>> mp;
        for (int i = 0; i < n; i++) {

            if (mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = {0, 0};
                count++;
            }
            mp[nums[i]].first++;
            mp[nums[i]].second = i;

            while (count > k) {
                mp[nums[pos]].first--;
                if (mp[nums[pos]].first == 0) {
                    mp.erase(nums[pos]);
                    count--;
                }
                pos++;
            }

            int mn = INT_MAX;
            for (auto e: mp) {
                mn = min(mn, e.second.second);
            }

            if (count == k) {
                ans += (mn - pos + 1);
            }

            //cout << i << " " << mn << " " << pos << " " << count << endl;
        }
        return ans;
    }
};
