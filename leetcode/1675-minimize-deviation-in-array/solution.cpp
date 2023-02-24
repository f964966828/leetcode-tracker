class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mn = INT_MAX, ans = INT_MAX;
        for(int n: nums){
            if(n%2) n *= 2;
            pq.push(n);
            mn = min(n, mn);
        }
        
        while(!pq.empty()){
            int val = pq.top();
            pq.pop();
            ans = min(ans, val - mn);
            
            if(val%2)
                break;

            val /= 2;
            mn = min(mn, val);
            pq.push(val);
        }

        return ans;
    }
};
