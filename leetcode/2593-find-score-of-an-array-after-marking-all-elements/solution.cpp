class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> marked(n);
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<n; i++)
            pq.push({-nums[i], -i});
        
        long long score = 0;
        while(!pq.empty()){
            int value = -pq.top().first;
            int index = -pq.top().second;
            if(marked[index]){
                pq.pop();
            }else{
                score += value;
                marked[index] = 1;
                if(index-1 >= 0) marked[index-1] = 1;
                if(index+1 < n) marked[index+1] = 1;
            }
        }
        
        return score;
    }
};
