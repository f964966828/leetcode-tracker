class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> triplet(3, INT_MAX);
        for (int num : nums) {
            if (num <= triplet[0]) triplet[0] = num;
            else if (num <= triplet[1]) triplet[1] = num;
            else return true;
        }
        return false;
    }
};
