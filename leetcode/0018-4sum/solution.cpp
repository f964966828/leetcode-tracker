class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        set<vector<int>> s;
        for(int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++) {
                int k = j + 1, m = n - 1;
                while (k < m) {
                    long long num = (long long) nums[i] + nums[j] + nums[k] + nums[m];
                    if (num == target) {
                        s.insert({nums[i], nums[j], nums[k], nums[m]});
                    } 
                    
                    if (num - target <= 0) {
                        k++;
                    } else {
                        m--;
                    }
                }
            }
        }

        vector<vector<int>> ans;
        for(auto it: s) ans.push_back(it);

        return ans;   
    }
};
