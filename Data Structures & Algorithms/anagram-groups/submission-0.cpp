class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> ans ;
        for(auto &s:strs){
            auto k = s ;
            sort(k.begin(),k.end()) ;
            // if(ans.count(k)){
                ans[k].push_back(s) ;
            // }
            // else {
                // ans[k].push_back(s) ;
            // }
        }

        vector<vector<string>> kns ;
        for(auto &it:ans){
            kns.push_back(it.second) ;
        }

        return kns ;
    }
};
