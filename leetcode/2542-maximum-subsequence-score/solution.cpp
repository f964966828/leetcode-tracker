class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) vec.push_back({nums2[i], nums1[i]});
        
        sort(vec.rbegin(), vec.rend());
        
        priority_queue<int> pq;
        long long sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (pq.size() == k) sum -= -pq.top(), pq.pop();
            sum += vec[i].second;
            pq.push(-vec[i].second);
            if (pq.size() == k) ans = max(ans, sum * vec[i].first);
        }

        return ans;
    }
};
