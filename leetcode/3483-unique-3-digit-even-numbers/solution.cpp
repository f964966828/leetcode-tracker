class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10);
        for (int d : digits) freq[d]++;
        
        int ans = 0;
        for (int i = 100; i < 1000; i += 2) {
            vector<int> cur(10);
            int temp = i;
            while (temp) {
                cur[temp % 10]++;
                temp /= 10;
            }
            bool valid = true;
            for (int j = 0; j < 10; j++) {
                valid &= (cur[j] <= freq[j]);
            }
            if (valid) ans++;
        }
        return ans;
    }
};
