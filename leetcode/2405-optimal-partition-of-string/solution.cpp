class Solution {
public:
    int partitionString(string s) {
        set<char> st;
        int ans = 1;
        for(char ch: s){
            if(st.find(ch) != st.end()){
                st.clear();
                ans++;
            }
            st.insert(ch);
        }

        return ans;
    }
};
