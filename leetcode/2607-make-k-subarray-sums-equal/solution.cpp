class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size() % k;
        n = gcd(n, k - n);
        
        vector<vector<int>> groups(n);
        for(int i=0; i<arr.size(); i++){
            groups[i % k % n].push_back(arr[i]);
        }
        
        long long ans = 0;
        for(auto group: groups){
            sort(group.begin(), group.end());
            long long mid = group[group.size()/2];
            for(auto num: group){
                //cout << num << " ";
                ans += abs(num - mid);
            }
            //cout << endl;
        }
        
        return ans;
    }
};
