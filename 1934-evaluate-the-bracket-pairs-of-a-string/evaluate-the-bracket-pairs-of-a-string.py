class Solution:
    def evaluate(self, s: str, knowledge: list[list[str]]) -> str:
        lookup = {key: val for key, val in knowledge}

        res = []
        in_bracket = False
        current_key = []

        for char in s:
            if char == "(":
                in_bracket = True
                current_key = []
            elif char == ")":
                in_bracket = False
                key_str = "".join(current_key)
                res.append(lookup.get(key_str, "?"))
            else:
                if in_bracket:
                    current_key.append(char)
                else:
                    res.append(char)

        return "".join(res)