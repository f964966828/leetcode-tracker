class Solution {
public:
    int countPairs(vector<int> &nums, int threshold) {
        int count = 0;
        for(int i=0; i<nums.size()-1; i++) {
            if (nums[i+1] - nums[i] <= threshold) {
                count++;
                i++;
            }
        }
        return count;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        
        int l = 0, r = 1e9, ans;
        while (l <= r) {
            int mid = (l+r)/2;
            
            int count = countPairs(nums, mid);
            //cout << mid << "   " << count << endl;
            if (count >= p) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return ans;
    }
};
