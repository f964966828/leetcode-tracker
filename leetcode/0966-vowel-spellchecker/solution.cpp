class Solution {
public:
    unordered_set<string> wordSet;
    unordered_map<string, string> lowerMap, vowelMap;

    string devowel(string &s) {
        string t = s;
        for (char& c : t) c = isVowel(c) ? '*' : tolower(c);
        return t;
    }

    bool isVowel(char c) {
        c = tolower(c);
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        for (string &w : wordlist) {
            wordSet.insert(w);
            string lower = w;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

            if (!lowerMap.count(lower)) lowerMap[lower] = w;
            string vw = devowel(w);
            if (!vowelMap.count(vw)) vowelMap[vw] = w;
        }

        vector<string> ans;
        for (string &q : queries) {
            if (wordSet.count(q)) ans.push_back(q);
            else {
                string lower = q;
                transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

                if (lowerMap.count(lower)) ans.push_back(lowerMap[lower]);
                else {
                    string vq = devowel(q);
                    if (vowelMap.count(vq)) ans.push_back(vowelMap[vq]);
                    else ans.push_back("");
                }
            }
        }
        return ans;
    }
};

