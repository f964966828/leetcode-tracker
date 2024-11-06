class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int mx = 0, pmax = 0, pbit = -1;
        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i], bit = 0;
            while (temp) {
                bit += (temp % 2);
                temp /= 2;
            }

            if (bit != pbit) {
                pmax = mx;
                pbit = bit;
            }
            mx = max(mx, nums[i]);
            
            if (pmax > nums[i]) return false;
        }
        return true;
    }
};
