class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n=nums.size(),ans=nums[0],curMin=nums[0],curMax=nums[0] ;
        for(int i=1;i<n;i++){
            int temp = min({curMin*nums[i],curMax*nums[i],nums[i]}) ;
            curMax = max({curMin*nums[i],curMax*nums[i],nums[i]}) ;
            curMin = temp ;
            ans=max(ans,curMax) ;
        }
        return ans ;
    }
};
