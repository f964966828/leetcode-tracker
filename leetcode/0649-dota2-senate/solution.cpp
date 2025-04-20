using pii = pair<int, int>;

class Solution {
public:
    bool cmp(const pii &a, const pii &b) {
        if (a.second != b.second) {
            return a.second < b.second;
        } else {
            return a.first < b.first;
        }
    }

    string predictPartyVictory(string senate) {
        queue<pii> rq, dq;
        for (int i = 0; i < senate.size(); i++) {
            char ch = senate[i];
            if (ch == 'R') rq.push({i, 0});
            else dq.push({i, 0});
        }

        while (!rq.empty() && !dq.empty()) {
            pii r = rq.front(); rq.pop();
            pii d = dq.front(); dq.pop();
            if (cmp(r, d)) {
                rq.push({r.first, r.second + 1});
            } else {
                dq.push({d.first, d.second + 1});
            }
        }

        if (!rq.empty()) {
            return "Radiant";
        } else {
            return "Dire";
        }
    }
};
