bool cmp(int& a, int& b) {
    return a > b;
}

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end(), cmp);

        queue<int> q;
        for (int num: deck) {
            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
            q.push(num);
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
