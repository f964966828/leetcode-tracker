class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size(), l=0, r=n-1;
        while(numbers[l] + numbers[r] != target){
            if(numbers[l] + numbers[r] < target)
                l++;
            else
                r--;
        }

        return {l+1, r+1};
    }
};
