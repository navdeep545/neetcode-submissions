// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        int n = pairs.size() ;
        if(n == 1) return {pairs} ; if (n==0) return {} ;
        vector<vector<Pair>> ans ;
        ans.push_back(pairs) ;
        for(int i=1;i<n;i++){
            auto temp = pairs[i] ;
            int k = i ;
            while(pairs[k-1].key > temp.key){
                pairs[k] = pairs[k-1] ;
                k-- ;
            }
            pairs[k] = temp ;
            ans.push_back(pairs) ;
            // if(k == i) return ans ;
        }

        return ans ;
    }
};
