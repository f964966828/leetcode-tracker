class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        vector<int> dis;
        for (int i = 0; i < stations.size() - 1; i++) {
            dis.push_back(stations[i + 1] - stations[i]);
        }

        double l = 0, r = 1e9;
        while (l < r) {
            double mid = (l + r) / 2;
            long long count = 0;
            for (int & d : dis) {
                count += floor((double) d / mid - 1e-8);
            }
            if (count > k) {
                l = mid + 1e-8;
            } else {
                r = mid - 1e-8;
            }
        }

        return l;
    }
};
