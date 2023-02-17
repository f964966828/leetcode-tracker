class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram = list()
        for s in strs:
            freq = [0] * 26
            for ch in s:
                freq[ord(ch)-ord('a')] += 1
            anagram.append(tuple(freq))
        
        mp = dict()
        for a, s in zip(anagram, strs):
            if a not in mp.keys():
                mp[a] = list()
            mp[a].append(s)

        ans = list()
        for k in mp.keys():
            ans.append(mp[k])

        return ans
        
