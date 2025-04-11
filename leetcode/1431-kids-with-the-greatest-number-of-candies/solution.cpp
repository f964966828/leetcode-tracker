class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> flags;

        int mx = *max_element(candies.begin(), candies.end());
        for (int num : candies) {
            flags.push_back(num + extraCandies >= mx);
        }

        return flags;
    }
};
