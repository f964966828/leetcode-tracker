class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        const int N = nums.size();
        unordered_map<int, int> visited;
        for (const int &num : nums) {
            visited[num]+=1;
        }
        const int DISTINCT = visited.size();

        int l=0, r=0;
        int res=0;
        visited.clear();
        // 紀錄 [l, r) 區間
        while (l<N) {
        //while (r<N) { 
            while (r<N && visited.size()<DISTINCT) {
                visited[nums[r++]]+=1;
            }

            if (visited.size()==DISTINCT) {
                res += N-(r-1);
            }

            //while (l<r) {
                // 捨掉 nums[l]
                visited[nums[l++]] -= 1;
                if (visited[nums[l-1]]==0) {
                    visited.erase(nums[l-1]);
                //    break;
                //} else {
                //    res += N-(r-1);
                }
            //}
        }
        return res;       
    }
};
