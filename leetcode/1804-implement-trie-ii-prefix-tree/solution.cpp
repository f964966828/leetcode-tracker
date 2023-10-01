class Trie {
public:

    map<string, int> mp;

    Trie() {

    }
    
    void insert(string word) {
        mp[word]++;
    }
    
    int countWordsEqualTo(string word) {
        return mp[word];
    }

    bool checkPrefix(string word, string prefix) {
        if (word.size() < prefix.size()) {
            return false;
        }

        for (int i=0; i<prefix.size(); i++) {
            if (word[i] != prefix[i]) {
                return false;
            }
        }

        return true;
    }
    
    int countWordsStartingWith(string prefix) {
        auto iter = mp.lower_bound(prefix);
        int count = 0;
        while (iter != mp.end() && checkPrefix(iter->first, prefix)) {
            count += iter->second;
            iter++;
        }
        return count;
    }
    
    void erase(string word) {
        if (--mp[word] == 0) {
            mp.erase(word);
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
