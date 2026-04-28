class Solution {

const vector<vector<int>> dir = {{-1,0},{0,-1},{0,1},{1,0}} ;

bool dfs(vector<vector<char>>& board,int row,int col,string word,int idx){
    if(idx == word.size()) return true ;
    for(auto &d:dir){
        int x = row + d[0] ;
        int y = col + d[1] ;
        if(x < board.size() && y < board[0].size() && x >= 0 && y >= 0 && board[x][y] == word[idx]){
            board[x][y] = 0 ;
            if(dfs(board,x,y,word,idx+1)) return true ;
            board[x][y] = word[idx] ;
        }
    }

    return false ;
}

public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0]){
                    board[i][j] = 0 ;
                    if(dfs(board,i,j,word,1))  return true ;
                    board[i][j] = word[0] ;
                }
            }
        }

        return false ;
    }
};
