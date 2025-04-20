class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> mp;
        for (int num : answers) mp[num]++;
        
        int ans = 0;
        for (auto e : mp) {
            ans += (e.first + 1) * ((e.second + e.first) / (e.first + 1));
        }

        return ans;
    }
};
