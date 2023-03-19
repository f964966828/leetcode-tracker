class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count1(26), count2(26);
        for(char ch: ransomNote) count1[ch-'a']++;
        for(char ch: magazine) count2[ch-'a']++;
        
        for(int i=0; i<26; i++){
            if(count1[i] > count2[i])
                return false;
        }
        return true;
    }
};
