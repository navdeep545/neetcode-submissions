class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(),ans = nums[0],prev = nums[0] ;
        for(int i=1;i<n;i++){
            prev = max(prev + nums[i],nums[i]) ;
            ans = max(ans,prev) ;
        }
        return ans ;
    }
};
