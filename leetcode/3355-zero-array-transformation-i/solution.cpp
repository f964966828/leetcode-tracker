class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end());
        
        int l = 0, n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> decre(n);
        for (int i = 0; i < n; i++) {
            while (!pq.empty() && pq.top() < i) pq.pop();
            while (l < queries.size() && queries[l][0] <= i) pq.push(queries[l++][1]);
            decre[i] = pq.size();
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > decre[i]) return false;
        }

        return true;
    }
};
