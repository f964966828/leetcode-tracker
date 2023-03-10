class Solution {
public:

    bool cmp(string a, string b, vector<int> prior){
        for(int i=0; i<min(a.size(), b.size()); i++){
            if(a[i] != b[i])
                return prior[a[i]-'a'] < prior[b[i]-'a'];
        }

        return a.size() <= b.size();
    }

    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> prior(26);
        for(int i=0; i<26; i++)
            prior[order[i]-'a'] = i;
        
        for(int i=1; i<words.size(); i++){
            if(!cmp(words[i-1], words[i], prior))
                return false;
        }

        return true;
    }
};
