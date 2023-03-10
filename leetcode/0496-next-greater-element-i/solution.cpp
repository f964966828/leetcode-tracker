class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec(1e5, -1);
        priority_queue<int> pq;
        for(int n: nums2){
            while(!pq.empty() && -pq.top() < n){
                vec[-pq.top()] = n;
                pq.pop();
            }
            pq.push(-n);
        }

        vector<int> ans;
        for(int n: nums1)
            ans.push_back(vec[n]);

        return ans;
    }
};
