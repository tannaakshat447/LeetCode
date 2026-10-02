class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        result = []
        
        def backtrack(current: str, open_count: int, close_count: int):
            # Base case: valid combination of length 2 * n formed
            if len(current) == 2 * n:
                result.append(current)
                return
            
            # Can add '(' if we haven't used all n opening brackets
            if open_count < n:
                backtrack(current + "(", open_count + 1, close_count)
            
            # Can only add ')' if it won't exceed the number of '(' placed
            if close_count < open_count:
                backtrack(current + ")", open_count, close_count + 1)
        
        backtrack("", 0, 0)
        return result