class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        
        int n = reward1.size();
        vector<pair<int,int>> diff;
        for(int i=0; i<n; i++){
            diff.push_back({reward2[i] - reward1[i], i});
        }
        
        sort(diff.begin(), diff.end());
        
        int ans = 0;
        for(int i=0; i<n; i++){
            if(k){
                ans += reward1[diff[i].second];
                k--;
            }else{
                ans += reward2[diff[i].second];
            }
        }
        
        return ans;
    }
};
