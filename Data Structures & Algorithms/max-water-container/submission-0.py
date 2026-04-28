class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l,r,ans = 0,len(heights)-1,0
        while r > l:
            area = abs(r-l) * min(heights[l],heights[r]) 
            ans = max(ans,area) 
            if heights[l] <= heights[r]:
                l += 1 
            else:
                r -= 1
        
        return ans