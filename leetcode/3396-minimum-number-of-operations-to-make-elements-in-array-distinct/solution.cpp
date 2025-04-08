class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        reverse(nums.begin(), nums.end());
        
        int flag[105] = {0};
        int pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (flag[num]) break;
            flag[num] = 1;
            pos++;
        }

        int remain = nums.size() - pos;
        return (remain / 3) + (remain % 3 != 0);
    }
};
