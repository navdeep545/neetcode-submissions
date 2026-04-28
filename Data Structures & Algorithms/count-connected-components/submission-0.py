class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:

        def dfs(vis:List[bool],adj:List[List[int]],u:int):
            if vis[u]:
                return 
            vis[u] = True
            for v in adj[u]:
                if not vis[v]:
                    dfs(vis,adj,v)
            return 
        
        ans = 0
        vis = [False]*n
        adj = [[] for _ in range(n)]

        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)
        
        for u in range(n):
            if not vis[u]:
                ans += 1
                dfs(vis,adj,u)

        return ans
