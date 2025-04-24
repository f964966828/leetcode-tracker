class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n);
        candies[0] = candies[n - 1] = 1;
        for (int i = 1; i < n; i++) {
            candies[i] = (ratings[i] > ratings[i - 1] ? candies[i - 1] + 1 : 1);
        }
        for (int i = n - 1; i >= 1; i--) {
            candies[i - 1] = (ratings[i] < ratings[i - 1] ? max(candies[i - 1], candies[i] + 1) : candies[i - 1]);
        }

        int sum = 0;
        for (int &candy : candies) sum += candy;

        return sum;
    }
};
