class Solution {
public:
    bool canJump(vector<int>& nums,int idx=0) {
        int n = nums.size() ;
        if(idx == n-1) return true ;
        if(nums[idx] == 0 ) return false ;

        for(int i=1;i<=nums[idx];i++){
            if(canJump(nums,idx+i)) return true ;
        }

        return false ;
    }
};
