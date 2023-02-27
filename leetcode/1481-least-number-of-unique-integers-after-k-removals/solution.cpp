class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> mp;
        for(int n: arr) mp[n]++;
        
        priority_queue <int, vector<int>, greater<int>> pq;
        for(auto e: mp) pq.push(e.second);

        while(k-pq.top()>=0){
            k -= pq.top();
            pq.pop();
        }

        return pq.size();
    }
};
