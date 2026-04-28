class Solution {

int fun(int n){
    int cnt = 0 ;
    while(n){
        if(1&n){
            cnt++ ;
        }
        n = (n>>1) ;
    }
    return cnt ;
}

public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0) ;
        for(int i=1;i<=n;i++){
            ans[i] = fun(i) ;
        }
        return ans ;
    }
};
