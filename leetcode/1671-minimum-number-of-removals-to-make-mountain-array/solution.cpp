class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n), lds(n), seq;

        for(int i = 0; i < n; i++){
            int idx = lower_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
            if (idx == seq.size()) seq.push_back(nums[i]);
            else seq[idx] = nums[i];
            lis[i] = seq.size() - 1;
        }

        seq.clear();
        for(int i = n - 1; i >= 0; i--){
            int idx = lower_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
            if (idx == seq.size()) seq.push_back(nums[i]);
            else seq[idx] = nums[i];
            lds[i] = seq.size() - 1;
        }

        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (lis[i] && lds[i]) mx = max(mx, lis[i] + lds[i] + 1);
        }

        return n - mx;
    }
};
