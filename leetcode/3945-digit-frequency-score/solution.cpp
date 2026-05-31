class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> freq(10);
        while (n) {
            freq[n % 10]++;
            n /= 10;
        }
        int ans = 0;
        for (int i = 0; i < 10; i++) ans += i * freq[i];
        return ans;
    }
};
