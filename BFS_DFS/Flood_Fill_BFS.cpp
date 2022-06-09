//

class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        return (i>=0 && i<m && j>=0 && j<n);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // bfs
        int m=image.size();
        int n=image[0].size();
        
        queue<pair<int,int>> mQ;

        
        int oldColor = image[sr][sc];
        if(oldColor==newColor)return image;
        
        image[sr][sc]=newColor;
        mQ.push({sr,sc});
        while(!mQ.empty()){
            int i,j;
            i = mQ.front().first;
            j = mQ.front().second;
            mQ.pop();
            

            if(isValid(i+1,j,m,n) && image[i+1][j]==oldColor){
                image[i+1][j]=newColor;    
                mQ.push({i+1,j});        
            }
            if(isValid(i,j+1,m,n) && image[i][j+1]==oldColor){
                image[i][j+1]=newColor;
                mQ.push({i,j+1});        
            }
            if(isValid(i-1,j,m,n) && image[i-1][j]==oldColor){
                image[i-1][j]=newColor;
                mQ.push({i-1,j});
                      
            }
            if(isValid(i,j-1,m,n) && image[i][j-1]==oldColor){
                image[i][j-1]=newColor;
                mQ.push({i,j-1});
            }
            
        }
        
        return image;
    }
};