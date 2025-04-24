class Trie {
public:
    set<string> s;

    Trie() {
            
    }
    
    void insert(string word) {
        s.insert(word);
    }
    
    bool startsWith(string str, string prefix) {
        if (str.size() < prefix.size()) {
            return false;
        }
        for (int i = 0; i < prefix.size(); i++){
            if (str[i] != prefix[i]) return false;
        }
        return true;
    }

    vector<string> searchPrefix(string prefix) {
        auto iter = s.lower_bound(prefix);

        vector<string> strs;
        while (iter != s.end() && startsWith(*iter, prefix) && strs.size() < 3) {
            strs.push_back(*(iter++));
        }
        return strs;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;
        for (string product : products) trie.insert(product);

        vector<vector<string>> ans;
        string prefix = "";
        for (char ch : searchWord) {
            prefix.push_back(ch);
            ans.push_back(trie.searchPrefix(prefix));
        }

        return ans;
    }
};
