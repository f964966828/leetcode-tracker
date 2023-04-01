class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int exist1[10] = {0}, exist2[10] = {0};
        for(int num: nums1) exist1[num] = 1;
        for(int num: nums2) exist2[num] = 1;
        
        int mn1 = 9, mn2 = 9;
        for(int i=0; i<=9; i++){
            if(exist1[i]) mn1 = min(mn1, i);
            if(exist2[i]) mn2 = min(mn2, i);
            if(exist1[i] && exist2[i]) return i;
        }
        
        return min(mn1, mn2) * 10 + max(mn1, mn2);
    }
};
