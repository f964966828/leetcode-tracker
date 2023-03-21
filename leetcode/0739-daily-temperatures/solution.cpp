class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        vector<int> ans(n);

        priority_queue<vector<int>> pq;
        for(int i=0; i<n; i++){
            int t = temperatures[i];
            while(!pq.empty() && t > -pq.top()[0]){
                ans[pq.top()[1]] = i - pq.top()[1];
                pq.pop();
            }
            pq.push({-t, i});
        }

        return ans;
    }
};
