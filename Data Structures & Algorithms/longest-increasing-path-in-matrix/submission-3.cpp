class Solution {
    int rows,columns ;
    vector<vector<int>> dir ;

    int solve(unordered_set<int>& vis,vector<vector<int>>& mat,int row,int col){
        int ans = 1 ;

        for(auto &d:dir){
            int x = row + d[0] ;
            int y = col + d[1] ;
            if(x >= 0 && y >= 0 && x < rows && y < columns && !vis.count(x*columns + y) && mat[x][y] > mat[row][col]){
                vis.insert(x*columns + y) ;
                ans = max(ans,1+solve(vis,mat,x,y)) ;
                vis.erase(x*columns + y) ;
            }
        }

        return ans ;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size(),columns = matrix[0].size() ;
        dir = {
            {0,1},
            {1,0},
            {-1,0},
            {0,-1}
        } ;
int ans = 1 ;

unordered_set<int> vis ;
for(int i=0;i<rows;i++){
    for(int j=0;j<columns;j++){
        vis.insert(i*columns+j) ;
        ans = max(ans,solve(vis,matrix,i,j)) ;
        vis.erase(i*columns+j) ;
    }
}

        return  ans ;
    }
};
