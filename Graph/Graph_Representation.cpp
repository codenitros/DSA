// https://www.geeksforgeeks.org/graph-and-its-representations/

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}


int main(){
    int V=5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    return 0;
}


// Adjacency matrix to Adjacency list

vector<int> constructAdjacencyList(vector<vector<int>> mat){
    vector<int> adj[mat.size()];
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            if(mat[i][j]==1){
                adj[i].push_back(j);
            }
        }
    }
    return adj;
}