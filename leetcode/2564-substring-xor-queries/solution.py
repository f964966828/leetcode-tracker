class Solution:
    def substringXorQueries(self, s: str, queries: List[List[int]]) -> List[List[int]]:
        mp = dict()
        for i in range(len(s)):
            for j in range(50):
                if i+j <= len(s) and s[i:i+j] not in mp:
                    mp[s[i:i+j]] = [i, i+j-1]
        
        ans = list()
        for q in queries:
            tar = q[0]^q[1]
            ts = ""
            while tar:
                ts += str(tar%2)
                tar //= 2
            ts = ts[::-1]
            
            if ts == "":
                ts = "0"
            
            if ts in mp:
                ans.append(mp[ts])
            else:
                ans.append([-1, -1])
            
        return ans
        
