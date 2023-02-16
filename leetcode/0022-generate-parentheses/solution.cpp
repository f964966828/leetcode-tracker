class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        if(n == 0){
            vec.push_back("");
        }else{
            for(int i=0; i<n; i++){
                for(auto left: generateParenthesis(i)){
                    for(auto right: generateParenthesis(n-1-i)){
                        vec.push_back("(" + left + ")" + right);
                    }
                }
            }
        }
        return vec;
    }
};
