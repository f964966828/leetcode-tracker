class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int count = 0, odd_min = INT_MAX, even_min = INT_MAX;
        for (int num : nums1) {
            if (num % 2) {
                count++;
                odd_min = min(odd_min, num);
            } else {
                even_min = min(even_min, num);
            }
        }

        return count == 0 || odd_min < even_min;
    }
};
