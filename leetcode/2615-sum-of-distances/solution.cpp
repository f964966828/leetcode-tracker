class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<long long>> index_map;
        for(int i=0; i<n; i++) {
            index_map[nums[i]].push_back(i);
        }
        
        vector<long long> ans(n);
        for(auto item: index_map) {
            vector<long long> seq = item.second, psum(1);
            
            int m = seq.size();
            for(int i=1; i<=m; i++) {
                psum.push_back(psum[i-1] + seq[i-1]);
            }
            
            for(int i=0; i<m; i++) {
                long long left = (i + 1) * seq[i] - psum[i+1];
                long long right = (psum[m] - psum[i+1]) - (m-i-1) * seq[i];
                ans[seq[i]] = left + right;
            }
        }
        
        return ans;
    }
};
