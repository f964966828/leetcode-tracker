class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int, int> mp;
        for (int & num : nums) mp[(num % value + value) % value]++;
        
        int val = 0;
        for (int i = 1; i < value; i++) {
            if (mp[i] < mp[val]) val = i;
        }
        
        return value * mp[val] + val;
    }
};
