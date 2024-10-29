class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), m = costs[0].size();
        int mn1 = INT_MAX, mn2 = INT_MAX, mni = 0;
        for (int j = 0; j < m; j++) {
            if (costs[0][j] < mn1) {
                mn1 = costs[0][j];
                mni = j;
            }
            cout << mn1 << endl;
        }
        for (int j = 0; j < m; j++) {
            if (j != mni && costs[0][j] < mn2) {
                mn2 = costs[0][j];
            }
        }

        for (int i = 1; i < n; i++) {
            vector<int> nums;
            for (int j = 0; j < m; j++) {
                if (mni != j) {
                    nums.push_back(costs[i][j] + mn1);
                } else {
                    nums.push_back(costs[i][j] + mn2);
                }
            }

            mn1 = mn2 = INT_MAX;
            for (int j = 0; j < m; j++) {
                if (nums[j] < mn1) {
                    mn1 = nums[j];
                    mni = j;
                }
            }
            for (int j = 0; j < m; j++) {
                if (j != mni && nums[j] < mn2) {
                    mn2 = nums[j];
                }
            }
        }

        return mn1;
    }
};
