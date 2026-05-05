class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        
        self.st = set()
        n = len(nums)
        nums.sort()
        def dp(i, curr):
            if i == n:
                self.st.add(tuple(curr))
                return
            curr.append(nums[i])
            dp(i+1, curr)
            curr.pop()
            while i+1 < n and nums[i] == nums[i+1]:
                i += 1
            dp(i+1, curr)
            return

        dp(0,[])

        return list(self.st)
