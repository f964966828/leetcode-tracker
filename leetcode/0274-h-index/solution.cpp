class Solution {
public:
    int hIndex(vector<int>& citations) {
        short mx = *max_element(citations.begin(), citations.end());
        vector<short> counts(mx + 1);
        for (int &num : citations) counts[num]++;
        
        int count = 0;
        for (short i = mx; i >= 0; i--) {
            count += counts[i];
            if (count >= i) return i;
        }

        return 0;
    }
};
