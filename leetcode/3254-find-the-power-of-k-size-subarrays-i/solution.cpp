class Solution {
public:
    bool valid(vector<int>& arr) {
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] + 1 != arr[i + 1]) return false;
        }
        return true;
    }

    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans, temp;
        int n = nums.size();

        for (int i = 0; i < k; i++) temp.push_back(nums[i]);
        ans.push_back(valid(temp) ? temp[k - 1] : -1);

        for (int i = k; i < n; i++) {
            temp.erase(temp.begin());
            temp.push_back(nums[i]);
            ans.push_back(valid(temp) ? temp[k - 1] : -1);
        }

        return ans;
    }
};
