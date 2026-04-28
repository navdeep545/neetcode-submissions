class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        s1 = set() ;
        l,ans = 0,0
        for i in range(len(s)):
            while s[i] in s1:
                s1.remove(s[l])
                l += 1
            s1.add(s[i])
            ans = max(ans,i-l+1)
        
        return ans 