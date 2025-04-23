class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> vec(100);
        for (int i = 0; i <= n; i++) {
            int count = 0, temp = i;
            while (temp) {
                count += (temp % 10);
                temp /= 10;
            }
            if(count) vec[count]++;
        }

        int mx = *max_element(vec.begin(), vec.end());
        int ans = 0;
        for (int num : vec) ans += (num == mx);
        return ans;
    }
};
