class Solution {
public:
    int countElements(vector<int>& arr) {
        vector<int> counts(1001);
        for (int &num : arr) counts[num]++;

        int ans = 0;
        for (int i = 0; i < 1000; i++) {
            if (counts[i + 1]) ans += counts[i];
        }

        return ans;
    }
};
