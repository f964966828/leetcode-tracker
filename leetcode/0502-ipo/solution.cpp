typedef pair<int,int> pii;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pii> info(n);
        for(int i=0; i<n; i++){
            info[i].first = capital[i];      
            info[i].second = profits[i];
        }
        sort(info.begin(), info.end());

        priority_queue<int> pq;
        
        int idx = 0;
        while(k--){
            while(idx < n && info[idx].first <= w){
                pq.push(info[idx].second);
                idx++;
            }
            if(!pq.empty()){
                w += pq.top();
                pq.pop();
            }
        }

        return w;
    }
};
