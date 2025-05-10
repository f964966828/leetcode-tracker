class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<int>> mp;
        set<int> zeros;
        for (int i = 0; i < n; i++) {
            if (nums[i]) mp[nums[i]].push_back(i);
            else zeros.insert(i);
        }
            
        int ans = 0;
        while (!mp.empty()) {
            int val = mp.begin()->first;
            vector<int> indices = mp.begin()->second;

            ans++;
            int cur = indices[0];
            for (int i = 1; i < indices.size(); i++) {
                int next = indices[i];
                auto iter = zeros.lower_bound(cur);
                if (iter != zeros.end() && *iter < next) ans++;
                zeros.insert(cur);
                cur = next;
            }
            zeros.insert(cur);
            mp.erase(mp.begin());
        }

        return ans;
    }
};
