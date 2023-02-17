class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for(auto it: nums) mp[it]++;
        
        multiset<pair<int,int>> ms;
        for(auto it: mp) ms.insert({-it.second, it.first});
        
        vector<int> ans;
        for(auto it: ms){
            ans.push_back(it.second);
            if(--k == 0) break;
        }

        return ans;
    }
};
