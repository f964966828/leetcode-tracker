class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        map<int, int> mp;
        for(int n: nums)
            mp[n]++;
        
        int mx = 0;
        for(auto e: mp)
            mx = max(mx, e.second);
        
        return nums.size() - mx;
    }
};
