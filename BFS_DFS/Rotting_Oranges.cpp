// https://leetcode.com/problems/rotting-oranges/

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
class Solution {
    int count=0;
public:
    
    bool isValid(int i,int j, int n, int m){
        return i<n && j<m && i>=0 && j>=0;
    }
    
    bool isAllRotten(vector<vector<int>>& mat){
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1)return false;
            }
        }
        return true;
    }
    
    void rotOranges(vector<vector<int>>& mat){
        
        // level order traversal approach
        queue<pair<int,int>> myQ;
        int n=mat.size();
        int m=mat[0].size();
        
        // put all the index that has rotten oranges
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2){
                    myQ.push({i,j});
                }
            }
        }
        
        while(!myQ.empty())
        {
            // flag that helps to understand whether we rotted atleast 1 orange in this level
            bool rotted=false;
            int s=myQ.size();
            // level order traversal logic
            while(s--){
                auto [x,y] = myQ.front();
                myQ.pop();
                for(int k=0;k<4;k++){
                    int nx=x+dx[k],ny=y+dy[k];
                    if(isValid(nx,ny,n,m))
                    {
                        if(mat[nx][ny]==1){
                            mat[nx][ny]=2;
                            if(!rotted){
                                count++;
                                rotted=true;
                            }
                            myQ.push({nx,ny});
                        }
                    }
                }
            }
        }
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        if(isAllRotten(grid))return 0;
        rotOranges(grid);
        return isAllRotten(grid)?count:-1;
    }
};