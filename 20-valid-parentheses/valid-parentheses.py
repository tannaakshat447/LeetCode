class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for i in s:
            if i == '(' or i == '[' or i == '{':
                stack.append(i)
            else:
                if len(stack) != 0:
                    if i == ')' and stack[len(stack)-1] != '(':
                        return False
                    if i == ']' and stack[len(stack)-1] != '[':
                        return False
                    if i == '}' and stack[len(stack)-1] != '{':
                        return False
                    stack.pop()
                else:
                    return False
        return len(stack) == 0