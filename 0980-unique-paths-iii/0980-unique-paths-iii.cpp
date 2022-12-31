// Daily Challenge 
class Solution {
public:
    int R, C;
    int startI, startJ;
    int endI, endJ;
    int totEmpty;
    vector<int> x {0,0,-1,+1};
    vector<int> y {-1,+1,0,0};
    
    int foo(int i, int j, int visitRemain,vector<vector<int>>& grid){
        
        //visitRemain = number of nodes that still need to be visited 
        
        if(i == endI && j == endJ){
            return visitRemain == 0;
        }

        int totWays = 0;

        grid[i][j] = -1;//marking the current node as visited

        for(int d=0;d<4;d++){
            int newI = i + x[d];
            int newJ = j + y[d];
            if(inBounds(newI, newJ) && grid[newI][newJ] != -1){
                totWays += foo(newI, newJ, visitRemain - 1, grid);
            }
        }

        grid[i][j] = 0; //Backtracking!

        return totWays;
    }


    int uniquePathsIII(vector<vector<int>>& grid) {
        this->R = grid.size();
        this->C = grid[0].size();
        this->totEmpty = 0;

        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                if(grid[i][j] == 1) {startI = i; startJ = j;}
                else if(grid[i][j] == 2) {endI = i; endJ=j;}
                else if(grid[i][j] == 0)    totEmpty++;
        
        totEmpty += 1; // since we have to count the destination also 

        return foo(startI, startJ, totEmpty, grid);
    }
    
    bool inBounds(int i, int j){
        return (i>=0 && i<R && j>=0 && j<C);
    }
};