// https://leetcode.com/problems/max-area-of-island/

/*
// Iterative Approach

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};


class Solution {
public:
    bool isValid(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    
    int bfs(vector<vector<int>>& grid, int n, int m, int i, int j){
        queue<pair<int, int>> mQ;
        int val=0;
        
        mQ.push({i,j});
        val++;
        grid[i][j]=2;
        
        while(!mQ.empty()){
            int k=mQ.size();
            while(k--){
                auto [x,y] = mQ.front();
                mQ.pop();
                
                for(int k=0;k<4;k++){
                    int nx=x+dx[k], ny=y+dy[k];
                    if(isValid(nx, ny, n, m) && grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        val++;
                        mQ.push({nx,ny});
                    }
                }
                
            }
        }
        return val;
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int maxi=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    maxi=max(maxi, bfs(grid, n, m, i, j));  
                }
            }
        }
        return maxi;
    }
};
*/

// Recursive dfs Approach

class Solution {
public:
    bool isValid(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    
    int dfs(vector<vector<int>>& grid, int n, int m, int i, int j){
        queue<pair<int, int>> mQ;
        
        if(isValid(i, j, n, m) && grid[i][j]==1){
            grid[i][j]=0;
            return 1 + dfs(grid, n, m, i, j+1)
                     + dfs(grid, n, m, i+1, j)
                     + dfs(grid, n, m, i-1, j) 
                     + dfs(grid, n, m, i, j-1);
        }
        return 0;
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int maxi=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    maxi=max(maxi, dfs(grid, n, m, i, j));  
                }
            }
        }
        return maxi;
    }
};