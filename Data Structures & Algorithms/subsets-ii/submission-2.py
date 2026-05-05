class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        
        st = []
        n = len(nums)
        nums.sort()
        def dp(i, curr, st):
            if i == n:
                st.append(curr[:])
                return
            curr.append(nums[i])
            dp(i+1, curr, st)
            curr.pop()
            while i+1 < n and nums[i] == nums[i+1]:
                i += 1
            dp(i+1, curr, st)
            return

        curr = []
        dp(0,curr, st)

        return st
