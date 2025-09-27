class Solution {
public:
    void dfs(int from, int gidx, vector<int>& member, vector<int>& group, vector<vector<int>>& adj_list) {
        group[from] = gidx;
        member.push_back(from);

        for (int & to : adj_list[from]) {
            if (group[to] == 0) dfs(to, gidx, member, group, adj_list);
        }
    }
    
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        int n = nums.size();
        vector<vector<int>> adj_list(n);
        for (auto & swap : swaps) {
            adj_list[swap[0]].push_back(swap[1]);
            adj_list[swap[1]].push_back(swap[0]);
        }
        
        int gidx = 1;
        vector<int> group(n);
        vector<vector<int>> members;
        for (int i = 0; i < n; i++) {
            if (group[i] == 0) {
                vector<int> member;
                dfs(i, gidx, member, group, adj_list);

                gidx++;
                members.push_back(member);
            }
        }

        long long ans = 0;
        for (auto & member : members) {
            int odd = 0;
            vector<int> vec;
            for (auto & idx : member) {
                odd += (idx % 2 == 1);
                vec.push_back(nums[idx]);
            }
            sort(vec.begin(), vec.end());
            for (int i = 0; i < odd; i++) ans -= vec[i];
            for (int i = odd; i < vec.size(); i++) ans += vec[i];
        }

        return ans;
    }
};
