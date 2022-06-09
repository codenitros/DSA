// https://www.codingninjas.com/codestudio/problems/print-all-possible-paths-from-top-left-corner-to-bottom-right-corner-of-a-2-d-matrix_1171152?leftPanelTab=0

bool isValid(int i, int j, vector<vector<int> > & mat){
    return (i>=0 && j>=0 && i<mat.size() && j<mat[0].size());
}

void getAllPaths(int row, int col, vector<int>& temp, vector<vector<int>> &mat,
				vector<vector<int>>& ans){
                
                if(row==mat.size()-1 && col==mat[0].size()-1){
                    temp.push_back(mat[row][col]);
                	ans.push_back(temp);
                    temp.pop_back();
                    return;
                }
                
                temp.push_back(mat[row][col]);
               
                if(isValid(row+1, col, mat)){
                	getAllPaths(row+1, col, temp, mat, ans);
                }
                if(isValid(row, col+1, mat)){
                	getAllPaths(row, col+1, temp, mat, ans);
                }
             	
                temp.pop_back();
}


vector<vector <int> > printAllpaths(vector<vector<int> > & mat , int m , int n)
{
    vector<vector<int>> ans;
    vector<int> temp;
    getAllPaths(0, 0, temp, mat, ans);
    return ans;
}
