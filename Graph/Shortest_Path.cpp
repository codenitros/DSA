//


void BFS(vector<int> adj[], int N, int src, vector<int>& dist){
    queue<int> mQ;
    mQ.push(src);// push source
    dist[src]=0; /// distance of src to src is 0

    while(!mQ.empty()){
        int node = mQ.front();
        mQ.pop();

        for(auto it:adj[node]){
            if(dist[node] + 1 < dist[it]){ 
                dist[it]=dist[node]+1; // if we found lower path update our dist
                mQ.push(it);// push to Queue
            }
        }
    }
}


int main(){
    vector<int> dist(V, INT_MAX); // initialize all distance with infinity
}