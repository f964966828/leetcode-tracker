class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        for(int n: nums) ans.push_back(n*n);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
