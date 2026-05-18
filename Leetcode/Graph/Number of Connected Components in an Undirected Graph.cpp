
class Solution {
    void dfs(int node,vector<bool> &visited,vector<vector<int>> &adj){
            visited[node]=true;
            for(auto neigh: adj[node]){
                if(visited[neigh]==0){
                    dfs(neigh,visited,adj);
                }
            }
        }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        //build the graph
        vector<vector<int>>adj(n);
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }        //adj list
        vector<bool>visited(n,0);
        //visited

        int count=0;
       //count=0
        
       for(int i=0;i<n;i++){
        if(visited[i]==0){
            count++;
            dfs(i,visited,adj);
        }
       }
        //for 0->n ->dfs : everytime you call count++
        return count;
    }
};
