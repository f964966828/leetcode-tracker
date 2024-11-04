class Solution {
public:
    string compressedString(string word) {
        char ch = word[0];
        int count = 1;
        vector<pair<char, int>> records;
        for (int i = 1; i < word.size(); i++) {
            if (ch != word[i]) {
                records.push_back({ch, count});
                ch = word[i];
                count = 1;
            } else {
                count++;
            }

            if (i == word.size() - 1) {
                records.push_back({ch, count});
            }
        }
        if (word.size() == 1) {
            records.push_back({ch, count});
        }

        string ans;
        for (auto record : records) {
            for (int i = 0; i < record.second / 9; i++) {
                ans += '9'; 
                ans += record.first;
            }
            if (record.second % 9) {
                ans += ('0' + record.second % 9);  
                ans += record.first;
            }
        }

        return ans;
    }
};
