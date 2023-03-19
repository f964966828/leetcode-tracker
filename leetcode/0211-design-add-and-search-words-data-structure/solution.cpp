class WordDictionary {
    vector<WordDictionary*> children;
    bool isEndOfWord;
public:
    WordDictionary(): isEndOfWord(false) {
        children = vector<WordDictionary*>(26, NULL);
    }
    
    void addWord(string word) {
        WordDictionary* curr = this;
        for(char each: word){
            if(curr->children[each-'a'] == NULL){
                curr->children[each-'a'] = new WordDictionary();
            }
            curr = curr->children[each-'a'];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        int i=0; WordDictionary* curr = this;
        for(char each: word){
            if(each=='.'){
                for(auto ch: curr->children)
                    if(ch && ch->search(word.substr(i+1))) return true;
                return false;
            }
            if(curr->children[each-'a']==NULL) return false;
            curr = curr->children[each-'a'];
            i++;
        }
        return curr && curr->isEndOfWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
