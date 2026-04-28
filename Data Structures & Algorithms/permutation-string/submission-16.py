class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n,m = len(s1), len(s2)
        if n > m:
            return False ;
        s1 = sorted(s1)
        for i in range(0,m):
            x = s2[i:i+n]
            print(x)
            x = sorted(x)
            if s1 == x:
                return True 

        return False 