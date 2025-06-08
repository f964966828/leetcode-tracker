class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        stack<int> q;
        q.push(0);
        while (!q.empty()) {
            int num = q.top();
            q.pop();

            if (num) ans.push_back(num);
            for (int i = 9; i >= 0; i--) {
                int next = num * 10 + i;
                if (next == 0 || next > n) continue;
                q.push(next);
            }    
        }
        return ans;
    }
};
