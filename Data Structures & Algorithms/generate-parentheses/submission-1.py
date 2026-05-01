class Solution:
    def generateParenthesis(self, n: int) -> List[str]:

        ans = set()

        def dfs(curr, open, closed):
            if open == 0 and closed == 0:
                ans.add(curr)
                return

            if open > 0:
                dfs(curr + "(", open-1, closed)
            
            
            if closed > open:
                dfs(curr + ")", open, closed-1)

            return
        
        dfs("", n, n)
        return list(ans)
        