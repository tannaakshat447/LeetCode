class Solution:
    def uniqueMorseRepresentations(self, words: list[str]) -> int:
        code = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]

        ans = []
        for word in words:
            morse = ""
            for letter in word:
                morse += code[ord(letter)-97]
            ans.append(morse)

        final = set(ans)
        return len(final)