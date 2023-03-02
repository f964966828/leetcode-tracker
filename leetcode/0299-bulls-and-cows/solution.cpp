class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> scnt(10), gcnt(10);
        
        int A = 0, B = 0; 
        for(int i=0; i<secret.size(); i++){
            int s = secret[i]-'0', g = guess[i]-'0';
            if(s == g)
                A++;
            else{
                scnt[s]++;
                gcnt[g]++;
            }
        }

        for(int i=0; i<10; i++) B += min(scnt[i], gcnt[i]);

        return to_string(A) + "A" + to_string(B) + "B";
    }
};
