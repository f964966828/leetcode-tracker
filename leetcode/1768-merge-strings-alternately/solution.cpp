class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int i=0;
        while(i < max(word1.length(), word2.length())*2){
            if(i%2){
                if(i/2 < word2.size())
                    ans += word2[i/2];
            }else{
                if(i/2 < word1.size())
                    ans += word1[i/2];
            }
            i++;
        }
        
        return ans;
    }
};
