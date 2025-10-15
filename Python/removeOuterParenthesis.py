class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        stack = []
        count = 0
        answer = []

        for char in s:
            stack.append(char)
            if char == '(':
                count += 1
            elif char == ')':
                count -= 1

            if count == 0:
                print(stack, answer)
                stack = []

        return "".join(answer)

sol = Solution()
print(sol.removeOuterParentheses("(()())(())(()(()))"))