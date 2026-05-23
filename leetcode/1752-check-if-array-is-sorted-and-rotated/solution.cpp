class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            bool flag = true;
            for (int j = 1; j < n; j++) {
                if (nums[(i + j + 1) % n] < nums[(i + j) % n]) flag = false;
            }
            if (flag) return true;
        }
        return false;
    }
};
