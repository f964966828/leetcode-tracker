class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0, pos = 0, n = tickets.size();
        while (true) {
            ans++;
            while (!tickets[pos]) pos = (pos + 1) % n;
            if (--tickets[pos] == 0 && pos == k) return ans;
            pos = (pos + 1) % n;
        }
    }
};
