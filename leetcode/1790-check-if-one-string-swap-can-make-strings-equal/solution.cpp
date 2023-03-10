class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> vec;
        for(int i=0; i<s1.size(); i++)
            if(s1[i] != s2[i]) vec.push_back(i);
            
        if(vec.size() == 0) 
            return true;
        else if(vec.size() == 2){
            int i1 = vec[0], i2 = vec[1];
            return (s1[i1] == s2[i2] && s1[i2] == s2[i1]);
        }

        return false;
    }
};
