class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int> s;
        int n = nums.size(), target = n * (n + 1) / 2, sum = 0, dup = -1;
        for (int num: nums) {
            sum += num;
            if (s.find(num) != s.end()) {
                dup = num;
            } else {
                s.insert(num);
            }
        }

        return {dup, target - sum + dup};
    }
};
