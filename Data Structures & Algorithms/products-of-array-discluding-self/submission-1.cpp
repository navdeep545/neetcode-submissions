class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pr = 1 ;
        int ind = -1,cnt=0 ;
        vector<int> ans(nums.size(),0) ;
        for(int i=0;i<nums.size();i++)
        { 
            if(nums[i] == 0) 
            {
                cnt++ ;
                ind = i ;
                if(cnt > 1) return ans ;
            } 
            else {
                pr *= nums[i] ;
            }
        }

        if(cnt){
            ans[ind] = pr ;
            return ans ;
        }

        for(int i=0;i<nums.size();i++){
            ans[i] = pr/nums[i] ;
        }

        return ans ;
    }
};
