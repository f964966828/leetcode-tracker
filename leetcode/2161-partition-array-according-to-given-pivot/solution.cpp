class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left, right;
        int count = 0;
        for (int num : nums) {
            if (num < pivot) left.push_back(num);
            else if (num == pivot) count++;
            else right.push_back(num);
        }

        vector<int> ans;
        for (int num : left) ans.push_back(num);
        while (count--) ans.push_back(pivot);
        for (int num : right) ans.push_back(num);
        return ans;
    }
};
