class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int push_i = 0, pop_i = 0;
        stack<int> st;
        while(push_i < pushed.size()){
            st.push(pushed[push_i++]);
            while(!st.empty() && pop_i < popped.size() && st.top() == popped[pop_i]) {
                st.pop();
                pop_i++;
            }
        }
        return (pop_i == popped.size()) ;
    }
};
