class Solution {
public:
    bool check(int i, int j, char c,vector<vector<char>>& board){
        int row= i-i%3;
        int col= j-j%3;
        
        for(int k=0;k<9;k++){
            if(board[i][k]==c) return false;
            if(board[k][j]==c) return false;
        }
        
        for(int k=0;k<3;k++){
            for(int l=0;l<3;l++){
                if(board[row+k][col+l]==c) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int n=board.size();
        int m= board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(check(i,j,c,board)){
                            board[i][j]=c;
                            if(solve(board)==true){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};