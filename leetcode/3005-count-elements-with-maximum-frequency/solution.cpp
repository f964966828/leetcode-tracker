class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[105] = {0};
        for (int & num : nums) freq[num]++;

        int mx = 0, count = 0;
        for (int i = 0; i <= 100; i++) {
            if (freq[i] > mx) {
                mx = freq[i];
                count = 1;
            } else if (freq[i] == mx) {
                count++;
            }
        }

        return mx * count;
    }
};
