class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int l = 0, r = min(tasks.size(), workers.size());
        while (l <= r) {
            int m = (l + r) / 2;
            int remain = pills;

            bool flag = true;
            multiset<int> mst(workers.end() - m, workers.end());
            for (int i = m - 1; i >= 0; i--) {
                auto iter1 = mst.lower_bound(tasks[i]);
                if (iter1 != mst.end()) {
                    mst.erase(iter1);
                } else if (remain) {
                    auto iter2 = mst.lower_bound(tasks[i] - strength);
                    if (iter2 != mst.end()) {
                        remain--;
                        mst.erase(iter2);
                    } else {
                        flag = false;
                        break;
                    }
                } else {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        } 

        return l - 1;
    }
};
