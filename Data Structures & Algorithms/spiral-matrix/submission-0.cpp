class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size() ;
        int left = 0, upper = 0, right = m-1, down = n-1 ;
        int cnt = n*m ;
        vector<int> ans ;
        while(left <= right && upper <= down){

            // top-left to top-right
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[upper][i]) ;
                cnt-- ;
            }
            upper++ ;
            if(!cnt) return ans ;

            // top-right to bottom-right
            for(int i=upper;i<=down;i++){
                ans.push_back(matrix[i][right]) ;
                cnt-- ;
            }
            right-- ;
            if(!cnt) return ans ;

            // bottom-right to bottom-left
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[down][i]) ;
                cnt-- ;
            }
            down-- ;
            if(!cnt) return ans ;

            // bottom-left to top-left
            for(int i=down;i>=upper;i--){
                ans.push_back(matrix[i][left]) ;
                cnt-- ;
            }
            left++ ;
            if(!cnt) return ans ;
        }

        return ans ;
    }
};