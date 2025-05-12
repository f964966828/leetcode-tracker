class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> counts(10);
        for (int &num : digits) counts[num]++;
        
        vector<int> ans;
        for (int i = 1; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k += 2) {
                    counts[i]--; counts[j]--; counts[k]--;
                    if (counts[i] >= 0 && counts[j] >= 0 && counts[k] >= 0) {
                        ans.push_back(i * 100 + j * 10 + k);
                    }
                    counts[i]++; counts[j]++; counts[k]++;
                }
            }
        }
        return ans;
    }
};
