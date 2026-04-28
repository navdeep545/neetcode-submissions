class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis ;
        lis.push_back(nums[0]) ;
        int n = nums.size() ;
        for(int i=1;i<n;i++){
            auto it = lower_bound(lis.begin(),lis.end(),nums[i]) ;
            if(it == lis.end()){
                lis.push_back(nums[i]) ;
            }
            else {
                *it = nums[i] ;
            }
        }

        return lis.size() ;
    }
};
