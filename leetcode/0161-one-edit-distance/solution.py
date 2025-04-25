class Solution:
    def isOneEditDistance(self, s: str, t: str) -> bool:
        if s == t:
            return False
        
        index = 0
        while index < min(len(s), len(t)) and s[index] == t[index]:
            index += 1
        
        # Insert
        if index < len(t) and s[:index] + t[index] + s[index:] == t:
            return True
        
        # Delete
        if s[:index] + s[index + 1:] == t:
            return True

        # Replace
        if index < len(t) and s[:index] + t[index] + s[index + 1:] == t:
            return True
        
        return False

