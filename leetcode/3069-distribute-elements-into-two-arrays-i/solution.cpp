class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1(1, nums[0]), arr2(1, nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            int num1 = arr1[arr1.size() - 1];
            int num2 = arr2[arr2.size() - 1];
            if (num1 > num2) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }
        for (int num : arr2) arr1.push_back(num);
        return arr1;
    }
};
