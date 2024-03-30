class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();
        
        vector<long long> ans;
        map<long long, long long> ids, counts;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (ids[num] != 0) {
                counts[ids[num]]--;
                if (counts[ids[num]] == 0) {
                    counts.erase(ids[num]);
                }
            }
            
            ids[nums[i]] += freq[i];
            
            if (ids[num] != 0) {
                counts[ids[num]]++;
            }
            
            if (counts.size() == 0) {
                ans.push_back(0);
            } else {
                ans.push_back((*(--counts.end())).first);   
            }
        }
        
        return ans;
    }
};
