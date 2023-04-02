class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> freq(n+1);
        for(int num: nums) freq[num]++;
        
        int row = 0;
        for(int f: freq) row = max(row, f);
        
        vector<vector<int>> ans(row);
        for(int i=0; i<row; i++){
            for(int j=1; j<=n; j++){
                if(freq[j]){
                    ans[i].push_back(j);
                    freq[j]--;
                }
            }
        }
        
        return ans;
    }
};
