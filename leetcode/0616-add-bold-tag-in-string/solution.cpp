class Solution {
public:
    bool match(string &source, string& target, int offset) {
        for (int i = 0; i < target.size(); i++) {
            if (target[i] != source[i + offset]) return false;
        }
        return true;
    }

    string addBoldTag(string s, vector<string>& words) {
        vector<pair<int, int>> itvs;
        for (string &word : words) {
            int n = s.size(), m = word.size();
            for (int i = 0; i <= n - m; i++) {
                if (match(s, word, i)) itvs.push_back({i, i + m});
            }
        }

        if (itvs.size() == 0) return s;
        
        sort(itvs.begin(), itvs.end());
        vector<pair<int, int>> merged;
        int start = itvs[0].first, end = itvs[0].second;
        for (auto &itv : itvs) {
            if (itv.first > end) {
                merged.push_back({start, end});
                start = itv.first;
            }
            end = max(end, itv.second);
        }
        merged.push_back({start, end});

        for (int i = merged.size() - 1; i >= 0; i--) {
            s.insert(merged[i].second, "</b>");
            s.insert(merged[i].first, "<b>");
        }

        return s;
    }
};
