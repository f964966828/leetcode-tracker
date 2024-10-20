class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        dictionary.sort()

        words = sentence.split()
        for i in range(len(words)):
            for root in dictionary[::-1]:
                if words[i].startswith(root):
                    words[i] = root
        
        return " ".join(words)

