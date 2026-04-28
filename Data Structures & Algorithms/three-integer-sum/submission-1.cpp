class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end()) ;
        vector<vector<int>> ans ;
        set<vector<int>> s ;
        for(int i = 0;i<nums.size();i++){
            int j=i+1,k=nums.size()-1 ;
            while(j < k){
                int x = nums[i] + nums[j] + nums[k] ;
                vector<int> p = {nums[i],nums[j],nums[k]} ;
                if(x == 0 && !s.count(p)){
                    s.insert(p) ;
                    ans.push_back(p) ;
                    j++ ;
                    k-- ;
                }
                else if(x < 0){
                    j++ ;
                }
                else {
                    k-- ;
                }
            }    
        }

        return ans ;
    }
};
