class Solution {
public:
    void sortColors(vector<int>& nums) {
        int counts[3] = {0};
        for (int &num : nums) counts[num]++;

        int i = 0;
        while (counts[0]) nums[i++] = 0, counts[0]--;
        while (counts[1]) nums[i++] = 1, counts[1]--;
        while (counts[2]) nums[i++] = 2, counts[2]--;
    }
};
