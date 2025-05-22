class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end());
        
        int l = 0, n = nums.size();
        priority_queue<int> queryQueue, remainQueue;
        for (int i = 0; i < n; i++) {
            while (l < queries.size() && queries[l][0] <= i) {
                remainQueue.push(queries[l++][1]);
            }
            while (!queryQueue.empty() && -queryQueue.top() < i) {
                queryQueue.pop();
            }
            while (!remainQueue.empty() && queryQueue.size() < nums[i]) {
                if (remainQueue.top() >= i) queryQueue.push(-remainQueue.top());
                remainQueue.pop();
            }
            if (queryQueue.size() < nums[i]) return -1;
        }

        return remainQueue.size();
    }
};
