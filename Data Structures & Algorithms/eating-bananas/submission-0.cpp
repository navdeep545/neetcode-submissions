class Solution {
private:
bool canEat(int mid, vector<int>& piles, int h){
    int ans = 0 ;
    for(int i=0;i<piles.size();i++){
        // if(piles[i] >= mid)
        ans += (piles[i]+mid-1)/mid ;
        // else ans++ ;
    }
    return ans <= h ;
}

public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int right=*max_element(piles.begin(),piles.end()) ;
        int left=1 ;
        int ans = INT_MAX;

        while(left<=right){
            int mid = left + (right-left)/2 ;
            if(canEat(mid,piles,h)){
                right = mid-1;
                ans = min(ans,mid) ;
            }
            else {
                left=mid+1 ;
            }
        }

        return ans ;
    }
};
