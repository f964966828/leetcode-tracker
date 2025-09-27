class Solution {
public:
    int minSplitMerge(vector<int>& src, vector<int>& des) {
        int n = src.size();
        set<vector<int>> visited;
        queue<pair<vector<int>, int>> q;
        
        q.push({src, 0});
        while (!q.empty()) {
            auto [nums, dist] = q.front();
            q.pop();

            if (nums == des) return dist;
            if (visited.find(nums) != visited.end()) continue;
            visited.insert(nums);

            for (int l = 0; l < n; l++) {
                for (int r = 0; r < n; r++) {
                    vector<int> subarray, remain;
                    for (int i = 0; i < n; i++) {
                        if (i >= l && i <= r) {
                            subarray.push_back(nums[i]);
                        } else{
                            remain.push_back(nums[i]);
                        }
                    }
                    for (int i = 0; i <= remain.size(); i++) {
                        vector<int> next(remain.begin(), remain.end());
                        next.insert(next.begin() + i, subarray.begin(), subarray.end());
                        if (visited.find(next) == visited.end()) q.push({next, dist + 1});
                    }
                }
            }
        }

        return -1;
    }
};
