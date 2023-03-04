class Solution {
public:
    int splitNum(int num) {
        string str = to_string(num), str1, str2;
        sort(str.begin(), str.end());
        for(int i=0; i<str.size(); i++){
            if(i%2)
                str1.push_back(str[i]);
            else
                str2.push_back(str[i]);
        }
        return stoi(str1) + stoi(str2);
    }
};
