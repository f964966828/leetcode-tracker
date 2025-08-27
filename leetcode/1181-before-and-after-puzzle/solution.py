class Solution:
    def beforeAndAfterPuzzles(self, phrases: List[str]) -> List[str]:
        phrase_words = [phrase.split() for phrase in phrases]
        merged_phrases = set()
        for i in range(len(phrase_words)):
            for j in range(len(phrase_words)):
                if i == j: continue
                if phrase_words[i][0] == phrase_words[j][-1]:
                    merged_phrases.add(" ".join(phrase_words[j] + phrase_words[i][1:]))
                if phrase_words[i][-1] == phrase_words[j][0]:
                    merged_phrases.add(" ".join(phrase_words[i] +phrase_words[j][1:]))
        
        merged_phrases = list(merged_phrases)
        merged_phrases.sort()
        return merged_phrases

