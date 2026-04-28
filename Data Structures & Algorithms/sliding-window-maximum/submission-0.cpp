class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deq ;
        vector<int> ans ;
        for(int i=0;i<k;i++){
                while(!deq.empty() && nums[deq.back()] < nums[i]){
                    deq.pop_back() ;
                }
                deq.push_back(i) ;
        }
        int left = 0 ;
        ans.push_back(nums[deq.front()]) ;
        for(int i=k;i<nums.size();i++){
            if(deq.front() == left){
                deq.pop_front() ;
            }
            left++ ;
            while(!deq.empty() && nums[deq.back()] < nums[i]){
                    deq.pop_back() ;
            }
            deq.push_back(i) ;
            ans.push_back(nums[deq.front()]) ;
        }

        return ans ;
    }
};
