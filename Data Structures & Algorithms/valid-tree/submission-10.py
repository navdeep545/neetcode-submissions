class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:

        visited = [0]*n
        adj_list = [[] for _ in range(n)]

        for e in edges:
            adj_list[e[0]].append(e[1])
            adj_list[e[1]].append(e[0])

        def dfs(node:int, parent:int) -> bool:

            visited[node] = 1 
            for p in adj_list[node]:
                if p != parent:
                    if visited[p] > 0:
                        return False
                    if  not dfs(p,node):
                        return False
                    
            return True
    
        if not dfs(0,-1):
            return False
        
        for v in visited:
            if v == 0:
                return False

        return True
            
        