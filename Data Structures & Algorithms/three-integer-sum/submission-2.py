from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()  # Sort the input array
        ans = []  # Store the result triplets
        
        for i in range(len(nums) - 2):  # Iterate through the array
            # Skip duplicates for the current element
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            j, k = i + 1, len(nums) - 1  # Two pointers
            
            while j < k:
                sum1 = nums[i] + nums[j] + nums[k]
                
                if sum1 == 0:
                    ans.append([nums[i], nums[j], nums[k]])  # Store the triplet
                    
                    # Move the pointers and skip duplicates
                    j += 1
                    k -= 1
                    while j < k and nums[j] == nums[j - 1]:
                        j += 1
                    while j < k and nums[k] == nums[k + 1]:
                        k -= 1
                
                elif sum1 < 0:
                    j += 1  # Increase the left pointer to get a larger sum
                else:
                    k -= 1  # Decrease the right pointer to get a smaller sum
        
        return ans
