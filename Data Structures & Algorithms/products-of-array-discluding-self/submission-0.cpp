class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pr = 1 ;
        vector<int> zeros ;
        vector<int> ans(nums.size(),0) ;
        for(int i=0;i<nums.size();i++)
        { 
            if(nums[i] == 0) 
            {
                zeros.push_back(i) ;
                if(zeros.size() > 1) return ans ;
            } 
            else {
                pr *= nums[i] ;
            }
        }

        if(!zeros.empty()){
            ans[zeros[0]] = pr ;
            return ans ;
        }
        for(int i=0;i<nums.size();i++){
            ans[i] = pr/nums[i] ;
        }

        return ans ;
    }
};
