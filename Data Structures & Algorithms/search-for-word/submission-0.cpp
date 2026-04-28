class Solution {

const vector<vector<int>> dir = {{-1,0},{0,-1},{0,1},{1,0}} ;

bool dfs(vector<vector<char>>& board,int row,int col,string word,set<pair<int,int>>& vis,int idx){
    if(idx == word.size()) return true ;
    for(auto &d:dir){
        int x = row + d[0] ;
        int y = col + d[1] ;
        if(x < board.size() && y < board[0].size() && x >= 0 && y >= 0 && board[x][y] == word[idx] && !vis.count({x,y})){
            vis.insert({x,y}) ;
            if(dfs(board,x,y,word,vis,idx+1)) return true ;
            vis.erase({x,y}) ;
        }
    }

    return false ;
}

public:
    bool exist(vector<vector<char>>& board, string word) {
        set<pair<int,int>> vis ;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0]){
                    vis.insert({i,j}) ;
                    if(dfs(board,i,j,word,vis,1))  return true ;
                    vis.erase({i,j}) ;
                }
            }
        }

        return false ;
    }
};
