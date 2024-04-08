class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int counts[2] = {0};
        queue<int> q;
        for (int num: students) {
            counts[num]++;
            q.push(num);
        }

        int pos = 0;
        while (!q.empty()) {
            int num = q.front(); q.pop();
            if (num == sandwiches[pos]) {
                pos++;
                counts[num]--;
            } else {
                q.push(num);
                if (counts[num] == q.size()) {
                    break;
                }
            }
        }

        return max(counts[0], counts[1]);
    }
};
