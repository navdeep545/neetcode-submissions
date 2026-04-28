class Solution {
string makes(int i,int j,int k){
    vector<int> p = {i,j,k} ;
    sort(p.begin(),p.end()) ;
    return to_string(p[0]) + to_string(p[1]) + to_string(p[2]) ;
}

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_set<string> set1 ;
        unordered_map<int,int> umap ;
        vector<vector<int>> ans ;
        int n=nums.size() ;
        for(int i=0;i<n;i++){
            umap[nums[i]] = i ;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x = (-1)*(nums[i]+nums[j]) ;
                if(umap.count(x) && umap[x] != i && umap[x] != j){
                    int k = umap[x] ;
                    string s = makes(nums[i],nums[j],nums[k]) ;
                    if(!set1.count(s))
                    {ans.push_back({nums[i],nums[j],nums[k]}) ;set1.insert(s) ;}
                }
            }
        }

        return ans ;
    }
};
