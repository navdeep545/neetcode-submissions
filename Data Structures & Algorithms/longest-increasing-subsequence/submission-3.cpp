class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size() ;
        vector<int> dp(n,1) ;
        for(int i=1;i<n;i++){
            int j = i-1 ;
            while(j>=0){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i],1+dp[j]) ;
                }
                j-- ;
            }
        }

        return *max_element(dp.begin(),dp.end()) ;
    }
};
