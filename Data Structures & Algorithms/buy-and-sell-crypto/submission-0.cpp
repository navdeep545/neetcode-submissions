class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = INT_MIN ;
        int left = 0,right = 1,n = prices.size() ;

        while(right < n){
            if(left == right) right++ ;
            if(right < n&&prices[right] > prices[left]){
                ans = max(ans,prices[right]-prices[left]) ;
                right++ ;
            }
            else left++ ;
        }

        return ans==INT_MIN?0:ans ;
    }
};
